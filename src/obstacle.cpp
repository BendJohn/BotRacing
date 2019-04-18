#include "obstacle.h"

obstacle::obstacle(ofVec2f v1, ofVec2f v2, ofVec2f v3, ofVec2f v4)
{
	top_corner = v1;
	top_boxsize = v2;
	bottom_corner = v3;
	bottom_boxsize = v4;
}

obstacle::obstacle()
{
	ofVec2f v1;
	v1.set(ofGetWindowWidth() / 2, 100);
	top_corner = v1;

	ofVec2f v2;
	v2.set(50, ofGetWindowHeight() - 100);
	top_boxsize = v2;

	ofVec2f v3;
	v3.set(ofGetWindowWidth() / 3, ofGetWindowHeight());
	bottom_corner = v3;

	bottom_boxsize = v2;
}

ofVec2f obstacle::getTopCorner()
{
	offset += 10;

	ofVec2f v1;
	v1.set(ofGetWindowWidth() / 2, 100 - offset % 100);
	top_corner = v1;
	
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
	ofVec2f v1;
	v1.set(ofGetWindowWidth() / 2, ofGetWindowHeight() - offset);
	return bottom_boxsize;
}

int obstacle::getOffset()
{
	return offset;
}