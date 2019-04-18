#include "ofApp.h"

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
	drawObstacle();
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
	ofSetColor(255, 255, 255);
}

void ofApp::drawRandomBot()
{
	ofVec2f top_position = rand1.getTopCorner();
	ofVec2f size = rand1.getSize();
	ofRectangle topHalf(top_position.x, top_position.y, size.x, size.y);
}