#pragma once
#include "ofMain.h"

// Enum that represents all possible directions that the bot can be moving
typedef enum {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
} BotDirection;
	
class randomBot {
	ofVec2f top_corner; // Tracking the top left corner of the bot
	ofVec2f boxsize; // Returns width, height
	
public:
	randomBot(); // Empty constructor
	randomBot(ofVec2f v1, ofVec2f v2); // Fill up with position and height
	BotDirection chooseDirection(); // Chooses a random direction
	void update(); // update the randomBot's position based on where it should move
	ofVec2f getTopCorner(); // Return top corner
	ofVec2f getSize(); // Return top size
};