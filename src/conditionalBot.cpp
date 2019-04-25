#include "conditionalBot.h"

using namespace gameEngine;

conditionalBot::conditionalBot()
{
	ofVec2f v1;
	v1.set(100, ofGetWindowHeight() / 3);
	top_corner = v1;

	ofVec2f v2;
	v2.set(20, 20);
	boxsize = v2;
}

conditionalBot::conditionalBot(ofVec2f v1, ofVec2f v2)
{
	top_corner = v1;
	boxsize = v2;
}

BotDirection conditionalBot::chooseDirection()
{
	BotDirection retDirection = RIGHT;
	return retDirection;
}

void conditionalBot::update()
{
	std::cout << "Conditional Bot shouldDelete Functions" << std::endl;

	obs.update();
	BotDirection next_move = chooseDirection();
	ofVec2f new_top_corner;

	if (next_move == RIGHT) {
		new_top_corner.set(top_corner.x + 10, top_corner.y);
		if (shouldDelete(new_top_corner, boxsize, obs)) {
			next_move == UP;
		}
	} /*
	else if (next_move == LEFT) {
		ofVec2f new_top_corner(top_corner.x - 10, top_corner.y);
		top_corner = new_top_corner;
	}*/
	if (next_move == UP) {
		new_top_corner.set(top_corner.x, top_corner.y - 10);
		if (shouldDelete(new_top_corner, boxsize, obs)) {
			next_move == DOWN;
		}
	}
	if (next_move == DOWN) {
		new_top_corner.set(top_corner.x, top_corner.y + 10);
	}
	top_corner = new_top_corner;

	std::cout << "End of Conditional Bot shouldDelete Functions" << std::endl;
}

ofVec2f conditionalBot::getTopCorner()
{
	return top_corner;
}

ofVec2f conditionalBot::getSize()
{
	return boxsize;
}

void conditionalBot::setSize(int a, int b)
{
	boxsize.set(a, b);
}