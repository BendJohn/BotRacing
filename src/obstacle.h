#pragma once
#include "ofMain.h"

class obstacle {
	ofVec2f top_corner; // Tracking the top left corner for bots
public:
	obstacle(); // Constructor given starting top left corner
	obstacle(ofVec2f v1); // Constructor given starting top left corner
};