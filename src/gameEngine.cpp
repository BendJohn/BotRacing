#include "gameEngine.h"
#include <iostream>

namespace gameEngine {
	bool isInObstacle(int bot_x, int bot_size, int obj_x, int obj_size)
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

	bool gameEngine::hasCrashed(ofVec2f bot_top_corner, ofVec2f bot_size, obstacle obj)
	{
		std::cout << bot_top_corner << std::endl;
		std::cout << bot_size << std::endl;
		std::cout << obj.getTopCorner() << std::endl;
		std::cout << obj.getTopSize() << std::endl;
		if (isInObstacle(bot_top_corner.x, bot_size.x, obj.getTopCorner().x, obj.getTopSize().x)) {
			if (isInObstacle(bot_top_corner.y, bot_size.y, obj.getTopCorner().y, obj.getTopSize().x)) {
				return true;
			}
		}

		return false;
	}

	bool shouldDelete(ofVec2f bot_top_corner, ofVec2f bot_size, obstacle obj)
	{
		// check for hitting obstacle from side
		if (hasCrashed(bot_top_corner, bot_size, obj)) {
			std::cout << "true" << std::endl;
			return true;
		}

		// check for hitting an obstacle from the top
		//if (hasCrashed(bot_top_corner.y, bot_size.y, obj.getTopCorner().y, obj.getTopSize().y)) {
		//	std::cout << "Hit obstacle from top" << std::endl;
		//	return true;
		//}

		// check for hitting top wall
		ofVec2f top_wall_corner(0, 0);
		ofVec2f top_wall_size(ofGetWindowWidth(), -100);
		obstacle top_wall(top_wall_corner, top_wall_size);
		if (hasCrashed(bot_top_corner, bot_size, top_wall)) {
			std::cout << "hit top wall" << std::endl;
			return true;
		}

		// check for hitting bottom wall
		ofVec2f bottom_wall_corner(0, ofGetWindowHeight());
		ofVec2f bottom_wall_size(ofGetWindowWidth(), 100);
		obstacle bottom_wall(bottom_wall_corner, bottom_wall_size);
		if (hasCrashed(bot_top_corner, bot_size, bottom_wall)) {
			std::cout << "hit bottom wall" << std::endl;
			return true;
		}

		// check for hitting left wall
		ofVec2f left_wall_corner(0, 0);
		ofVec2f left_wall_size(-100, ofGetWindowHeight());
		obstacle left_wall(left_wall_corner, left_wall_size);
		if (hasCrashed(bot_top_corner, bot_size, left_wall)) {
			std::cout << "hit left wall" << std::endl;
			return true;
		}

		// check for hitting right wall
		ofVec2f right_wall_corner(0, 0);
		ofVec2f right_wall_size(-100, ofGetWindowHeight());
		obstacle right_wall(right_wall_corner, right_wall_size);
		if (hasCrashed(bot_top_corner, bot_size, right_wall)) {
			std::cout << "hit right wall" << std::endl;
			return true;
		}

		std::cout << "false" << std::endl;
		return false;
	}
}