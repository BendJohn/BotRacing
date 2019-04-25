#include "ofApp.h"

using namespace gameEngine;

//--------------------------------------------------------------
void ofApp::setup(){
	// do some initialization

	// set the size of the window
	ofSetWindowShape(1000, 500);

	// set title of window
	ofSetWindowTitle("Bot Race");

	// set color of window to red (why not)

	// the rate at which the program runs (FPS)
	ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofImage background;
	background.load("botgame_bg.png");
	background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	// Draw game components
	drawObstacle();
	drawRandomBot();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	obs1.update();
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

	std::cout << "top position x" << std::endl;
	std::cout << top_position.x << std::endl;
	std::cout << "size" << std::endl;
	std::cout << size << std::endl;

	// Check if bot has crashed
	if (shouldDelete(top_position, size, obs1)) {
		rand1.setSize(0, 0);
	}

	ofRectangle bot(top_position.x, top_position.y, size.x, size.y);
	ofSetColor(225, 0, 0); // set color to red
	ofDrawRectangle(bot); // Draw random bot square
	ofSetColor(255, 255, 255); // revert color back to white
	rand1.update(); // Updates random bot movement
}