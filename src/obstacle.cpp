#include "obstacle.h"

obstacle::obstacle(ofVec2f v1, ofVec2f v2)
{
	top_corner = v1;
	top_boxsize = v2;
}

obstacle::obstacle()
{
	ofVec2f v1;
	v1.set(ofGetWindowWidth() / 2, 200);
	top_corner = v1;

	ofVec2f v2;
	v2.set(50, ofGetWindowHeight() - 200);
	top_boxsize = v2;

	ofVec2f v3;
	v3.set(ofGetWindowWidth() / 3, ofGetWindowHeight());
	bottom_corner = v3;

	bottom_boxsize = v2;
}

void obstacle::update()
{
	offset += 5;

	ofVec2f v1;
	v1.set(ofGetWindowWidth() / 2, 200 - offset % 170);
	top_corner = v1;

	ofVec2f v2;
	v2.set(ofGetWindowWidth() / 2, ofGetWindowHeight() - offset);
}

ofVec2f obstacle::getTopCorner()
{	
	return top_corner;
}

ofVec2f obstacle::getTopSize()
{
	return top_boxsize;
}

ofVec2f obstacle::getBottomCorner()
{
	return bottom_corner;
}

ofVec2f obstacle::getBottomSize()
{
	return bottom_boxsize;
}

int obstacle::getOffset()
{
	return offset;
}