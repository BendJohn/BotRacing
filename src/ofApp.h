#pragma once

#include "ofMain.h"
#include "ofxGraph.h"
#include "obstacle.h"
#include "randomBot.h"
#include "conditionalBot.h"
#include "gameEngine.h"
#include "simpleGeneticBot.h"
#include "population.h"

class ofApp : public ofBaseApp{
	private:
		obstacle obs1; // Holds information about moving rod.
		randomBot rand1;  // Holds information about the random bot.
		conditionalBot cond1; // Holds information about the conditional bot.
		simpleGeneticBot gen1; // Holds information about the simple genetic bot.
		population pop1; // Hold information about a population of simple genetic bots.
		void drawObstacle(); // Draw moving rod that the bots have to get through
		void drawRandomBot(); // Draw the random bot
		void drawConditionalBot(); // Draw the conditional bot
		void drawSimpleGeneticBot(simpleGeneticBot& gen, int r, int g, int b); // Draw the simple genetic bot
		void drawPopulation(); // Draw the population of the genetic bot.
		void drawMap(); // Draw map of genetic bot
		bool shouldDrawMap; // Whether or not to draw the map

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		const int OF_KEY_SPACE = 32;
		ofTrueTypeFont graphFont;
		ofxGraph graph;
};
