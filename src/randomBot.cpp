#include "randomBot.h"

randomBot::randomBot()
{
	ofVec2f v1;
	v1.set(100, ofGetWindowHeight() / 2);
	top_corner = v1;

	ofVec2f v2;
	v2.set(20, 20);
	boxsize = v2;
}

randomBot::randomBot(ofVec2f v1, ofVec2f v2)
{
	top_corner = v1;
	boxsize = v2;
}

ofVec2f randomBot::getTopCorner()
{
	return top_corner;
}

ofVec2f randomBot::getSize()
{
	return boxsize;
}
