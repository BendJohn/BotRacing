#pragma once
#include "ofMain.h"
#include "gameEngine.h"
	
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
	int getFitness(); // Get the "fitness" of this bot.
	void setSize(int a, int b); // Set the random bot's size (only called when set to 0 and exterminated)
};