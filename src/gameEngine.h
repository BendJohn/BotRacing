#pragma once
#include "ofMain.h"
#include <iostream>
#include "obstacle.h"

// Enum that represents all possible directions that the bot can be moving
typedef enum {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
} BotDirection;

namespace gameEngine {
	// check if point is in the obstacle
	bool isInObstacle(int bot_x, int bot_y, obstacle obj);
	// check if any of the corners of the bots are in the bot
	bool hasCrashed(ofVec2f bot_top_corner, ofVec2f bot_size, obstacle obj);
	//checks if the bot should be deleted
	bool shouldDelete(ofVec2f bot_top_corner, ofVec2f bot_size, obstacle obj);
}