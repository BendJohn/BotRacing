#pragma once
#include "ofMain.h"
#include "gameEngine.h"
#include <vector>

class simpleGeneticBot {
	ofVec2f top_corner; // Tracking the top left corner of the bot
	ofVec2f boxsize; // Returns width, height
	int move_number; // Returns which move this is
	vector<BotDirection> moves; // vector that holds sucessful moves
	BotDirection chooseDirection(); // Chooses a direction either randomly, or based on what it knows

public:
	simpleGeneticBot(); // Empty constructor
	simpleGeneticBot(ofVec2f v1, ofVec2f v2); // Fill up with position and height
	void update(); // update the randomBot's position based on where it should move
	ofVec2f getTopCorner(); // Return top corner
	ofVec2f getSize(); // Return top size
	void setSize(int a, int b); // Set the random bot's size (only called when set to 0 and exterminated)
};