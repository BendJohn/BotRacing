#include "obstacle.h"

obstacle::obstacle(ofVec2f v1)
{
	top_corner = v1;
}

obstacle::obstacle()
{
	ofVec2f v1;
	v1.set(ofGetWindowWidth() / 2, 100); // Preset this value to 
	top_corner = v1;
}