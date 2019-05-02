#include "ofApp.h"

using namespace gameEngine;

//--------------------------------------------------------------
void ofApp::setup(){
	// do some initialization
	shouldDrawMap = false;

	// set the size of the window
	ofSetWindowShape(1000, 500);

	// set title of window
	ofSetWindowTitle("Bot Race");

	// sync graph with vertical refresh rate
	ofSetVerticalSync(true);

	// ofxGraph uses ofxGui as a internal setting UI
	ofxGuiSetFont(ofToDataPath("ofxGraph/DIN Alternate Bold.ttf"), 10);

	// ofxGraph Init
	graph.setup("Genetic Bot Fitness");

	// Set Graph Image
	graph.setPosition(0, 100);
	float windowWidth = ofGetWindowWidth() * 1.0;
	float windowHeight = ofGetWindowHeight() * 1.0 - 100;
	graph.setSize(windowWidth, windowHeight);

	graph.setDx(1.0); // which means delta of time
	graph.setColor(ofColor::white);  // ofColor(255,255,255)
	graph.setLabel({ "Genetic Bot","Conditional Bot","Random Bot" });

	// the rate at which the program runs (FPS)
	ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){
	rand1.update(); // Updates random bot movement
	cond1.update(); // Updates random bot movement
	pop1.update(obs1);
	obs1.update();

	// Graphing!
	simpleGeneticBot& genBot = pop1.generation[0];
	int fitnessGen = genBot.getFitness();
	int fitnessRand = rand1.getFitness();
	int fitnessCond = cond1.getFitness();

	vector<float>value;
	value.push_back(fitnessGen * 1.0);
	value.push_back(fitnessRand * 1.0);
	value.push_back(fitnessCond * 1.0);

	graph.add(value);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofImage background;
	background.load("botgame_bg.png");
	background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	// Draw game components
	ofFill();
	drawRandomBot();
	drawConditionalBot();
	// drawSimpleGeneticBot(gen1);
	drawPopulation();
	drawObstacle();
	ofNoFill();
	if (shouldDrawMap) {
		drawMap();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int upper_key = toupper(key); // Standardize on upper case

	if (upper_key == OF_KEY_SPACE) {
		// Whether or not to draw the map
		shouldDrawMap = !shouldDrawMap;
	}

	if (upper_key == 'N') {
		// To skip a generation
		for (size_t i = 0; i < 10 * (pop1.getGen_number() + 1) - pop1.getRound(); i++) {
			pop1.update(obs1);
	obs1.update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	std::cout << "--------------Should Die------------------" << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawObstacle() {
	ofVec2f top_position = obs1.getTopCorner();
	ofVec2f bottom_position = obs1.getBottomCorner();
	ofVec2f top_size = obs1.getTopSize();
	ofVec2f bottom_size = obs1.getBottomSize();
	ofRectangle topHalf(top_position.x, top_position.y, top_size.x, top_size.y); // Create obstacle
	ofRectangle bottomHalf(bottom_position.x, bottom_position.y, bottom_size.x, bottom_size.y); // Create obstacle
	ofSetColor(0, 0, 255); // set color to blue
	ofDrawRectRounded(topHalf, 10, 10, 0, 0); // Draw obstacle
	ofSetColor(0, 255, 0); // set color to green
	ofDrawRectRounded(bottomHalf, 0, 0, 10, 10); // Draw obstacle
	ofSetColor(255, 255, 255); // revert color back to white
}

void ofApp::drawRandomBot()
{
	ofVec2f top_position = rand1.getTopCorner();
	ofVec2f size = rand1.getSize();

	// Check if bot has crashed
	if (shouldDelete(top_position, size, obs1)) {
		rand1.setSize(0, 0);
		return;
	}

	ofRectangle bot(top_position.x, top_position.y, size.x, size.y);
	ofSetColor(225, 0, 0); // set color to red
	ofDrawRectangle(bot); // Draw random bot square
	ofSetColor(255, 255, 255); // revert color back to white
}

void ofApp::drawConditionalBot()
{
	ofVec2f top_position = cond1.getTopCorner();
	ofVec2f size = cond1.getSize();

	// Check if bot has crashed
	if (shouldDelete(top_position, size, obs1)) {
		cond1.setSize(0, 0);
		return;
	}

	ofRectangle bot(top_position.x, top_position.y, size.x, size.y);
	ofSetColor(0, 100, 0); // set color to dark green
	ofDrawRectangle(bot); // Draw random bot square
	ofSetColor(255, 255, 255); // revert color back to white
}

void ofApp::drawSimpleGeneticBot(simpleGeneticBot& gen, int r, int g, int b)
{
	ofVec2f top_position = gen.getTopCorner();
	ofVec2f size = gen.getSize();

	// Check if bot has crashed
	if (shouldDelete(top_position, size, obs1)) {
		gen1.setSize(0, 0);
		return;
	}

	ofRectangle bot(top_position.x, top_position.y, size.x, size.y);
	ofSetColor(r, g, b); // set color to black
	ofDrawRectangle(bot); // Draw genetic bot square
	ofSetColor(255, 255, 255); // revert color back to white
	gen.update(); // Updates random bot movement
}

void ofApp::drawPopulation()
{
	for (size_t i = 1; i < pop1.generation.size(); i++) {
		simpleGeneticBot &gen_bot = pop1.generation[i];
		drawSimpleGeneticBot(gen_bot, 100, 100, 100);
	}

	simpleGeneticBot &gen_bot = pop1.generation[0];
	drawSimpleGeneticBot(gen_bot, 0, 0, 0); // set color to yellow
}

void ofApp::drawMap()
{
	// Set background to gray and draw
	ofBackground(50, 50, 50);
	graph.draw();
}