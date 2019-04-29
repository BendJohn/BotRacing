#include "simpleGeneticBot.h"

simpleGeneticBot::simpleGeneticBot()
{
	ofVec2f v1;
	v1.set(100, ofGetWindowHeight() / 3);
	top_corner = v1;

	ofVec2f v2;
	v2.set(20, 20);
	boxsize = v2;
}

simpleGeneticBot::simpleGeneticBot(ofVec2f v1, ofVec2f v2)
{
	top_corner = v1;
	boxsize = v2;
}

BotDirection simpleGeneticBot::chooseDirection()
{
	BotDirection random_dir = static_cast<BotDirection>(rand() % 4);
	return RIGHT;
}

void simpleGeneticBot::update()
{
	BotDirection next_move = chooseDirection();
	if (next_move == RIGHT) {
		ofVec2f new_top_corner(top_corner.x + 10, top_corner.y);
		top_corner = new_top_corner;
	}
	else if (next_move == LEFT) {
		ofVec2f new_top_corner(top_corner.x - 10, top_corner.y);
		top_corner = new_top_corner;
	}
	else if (next_move == UP) {
		ofVec2f new_top_corner(top_corner.x, top_corner.y - 10);
		top_corner = new_top_corner;
	}
	else {
		ofVec2f new_top_corner(top_corner.x, top_corner.y + 10);
		top_corner = new_top_corner;
	}
}

ofVec2f simpleGeneticBot::getTopCorner()
{
	return top_corner;
}

ofVec2f simpleGeneticBot::getSize()
{
	return boxsize;
}

void simpleGeneticBot::setSize(int a, int b)
{
	boxsize.set(a, b);
}