#pragma once
#include "ofMain.h"

class obstacle {
	ofVec2f top_corner; // Tracking the top left corner for bots
	ofVec2f top_boxsize; // Returns width, height
	ofVec2f bottom_corner; // Tracking the bottom left corner
	ofVec2f bottom_boxsize; // Returns width, height
	int offset; // offset of rects from starting position
public:
	obstacle(); // Preset this value to middle of screen at top
	obstacle(ofVec2f v1, ofVec2f v2, ofVec2f v3, ofVec2f v4); // Constructor given starting top left corner
	ofVec2f getTopCorner(); // Return top corner
	ofVec2f getTopSize(); // Return top size
	ofVec2f getBottomCorner(); // Return bottom corner
	ofVec2f getBottomSize(); // Return bottom size
	int getOffset(); // Return the offset value
};