#pragma once
#include "ofMain.h"
#include "obstacle.h"

// Enum that represents all possible directions that the bot can be moving
typedef enum {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
} BotDirection;

namespace gameEngine {
	// check if the bot has crashed
	bool hasCrashed(int bot_x, int bot_size, int obj_x, int obj_size);
	//checks if the bot should be deleted
	bool shouldDelete(ofVec2f bot_top_corner, ofVec2f bot_size, obstacle obj);
}