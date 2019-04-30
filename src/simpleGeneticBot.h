#pragma once
#include "ofMain.h"
#include "gameEngine.h"
#include <vector>

class simpleGeneticBot {
	ofVec2f top_corner; // Tracking the top left corner of the bot
	ofVec2f boxsize; // Returns width, height
	int move_number; // Returns which move this is
	vector<BotDirection> moves; // vector that holds sucessful moves
	vector<BotDirection> new_moves; // vector that holds this bot's new moves
	BotDirection chooseDirection(); // Chooses a direction either randomly, or based on what it knows

public:
	simpleGeneticBot(); // Empty constructor
	simpleGeneticBot(vector<BotDirection> dirs); // Fill up with position and height
	// simpleGeneticBot(simpleGeneticBot& copy_obj); // copies object
	void update(); // update the randomBot's position based on where it should move
	ofVec2f getTopCorner(); // Return top corner
	ofVec2f getSize(); // Return top size
	int getMoveNumber(); // Return move number
	int getFitness(); // Return the fitness of this organism
	vector<BotDirection> getNewMoves(); // Return vector of the new moves this bot took.
	void setSize(int a, int b); // Set the random bot's size (only called when set to 0 and exterminated)
};