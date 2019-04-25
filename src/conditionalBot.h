#pragma once
#include "ofMain.h"
#include "gameEngine.h"

class conditionalBot {
	ofVec2f top_corner; // Tracking the top left corner of the bot
	ofVec2f boxsize; // Returns width, height
	obstacle obs; // To keep track of obstacle motion

public:
	conditionalBot(); // Empty constructor
	conditionalBot(ofVec2f v1, ofVec2f v2); // Fill up with position and height
	BotDirection chooseDirection(); // Chooses a based on whether the next move is safe
	void update(); // update the randomBot's position based on where it should move
	ofVec2f getTopCorner(); // Return top corner
	ofVec2f getSize(); // Return top size
	void setSize(int a, int b); // Set the random bot's size (only called when set to 0 and exterminated)
};