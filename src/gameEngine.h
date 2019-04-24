#pragma once
#include "ofMain.h"

namespace gameEngine {
	// check if the bot has crashed
	bool hasCrashed(ofVec2f bot_top_corner, ofVec2f bot_size, ofvec2f obstacle_top_corner, ofvec2f obstacle_size);
	//checks if the bot should be deleted
	bool shouldDelete(ofVec2f bot_top_corner, ofVec2f bot_size);
}