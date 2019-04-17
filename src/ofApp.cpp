#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// do some initialization

	// set the size of the window
	ofSetWindowShape(1000, 500);

	// set title of window
	ofSetWindowTitle("Bot Race");

	// set color of window to red (why not)
	ofSetBackgroundColor(255, 0, 0);

	// the rate at which the program runs (FPS)
	ofSetFrameRate(15);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
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
	ofRectangle myRect(ofGetWindowWidth() / 2, 100, 50, ofGetWindowHeight() - 100); // Create obstacle
	ofSetColor(0, 0, 255); // set color to blue
	ofDrawRectRounded(myRect, 10); // Draw obstacle
}