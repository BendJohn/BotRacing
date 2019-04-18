#pragma once
#include "ofMain.h"

class randomBot {
	ofVec2f top_corner; // Tracking the top left corner of the bot
	ofVec2f boxsize; // Returns width, height
	
public:
	randomBot(); // Empty constructor
	randomBot(ofVec2f v1, ofVec2f v2); // Fill up with position and height
	ofVec2f getTopCorner(); // Return top corner
	ofVec2f getSize(); // Return top size
};