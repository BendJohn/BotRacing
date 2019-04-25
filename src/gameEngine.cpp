#include "gameEngine.h"
#include <iostream>

namespace gameEngine {
	bool hasCrashed(int bot_x, int bot_size, int obj_x, int obj_size)
	{
		// Check for top left corner hitting obstacle
		if (bot_x > obj_x && bot_x < obj_x + obj_size) {
			return true;
		}

		// Check for top right corner hitting obstacle
		if ((bot_x + bot_size) > obj_x && (bot_x + bot_size) < obj_x + obj_size) {
			return true;
		}

		return false;
	}

	bool shouldDelete(ofVec2f bot_top_corner, ofVec2f bot_size, obstacle obj)
	{
		// check for hitting obstacle from side
		if (hasCrashed(bot_top_corner.x, bot_size.x, obj.getTopCorner().x, obj.getTopSize().x)) {
			return true;
		}

		// check for hitting an obstacle from the top
		//if (hasCrashed(bot_top_corner.y, bot_size.y, obj.getTopCorner().y, obj.getTopSize().y)) {
		//	std::cout << "Hit obstacle from top" << std::endl;
		//	return true;
		//}

		// check for hitting top wall
		if (hasCrashed(bot_top_corner.x, bot_size.x, 0, -100)) {
			return true;
		}

		// check for hitting bottom wall
		if (hasCrashed(bot_top_corner.y, bot_size.y, ofGetWindowHeight(), 100)) {
			return true;
		}

		// check for hitting left wall
		if (hasCrashed(bot_top_corner.x, bot_size.x, obj.getTopCorner().x, obj.getTopSize().x)) {
			return true;
		}

		// check for hitting right wall
		if (hasCrashed(bot_top_corner.x, bot_size.x, obj.getTopCorner().x, obj.getTopSize().x)) {
			return true;
		}

		return false;
	}
}