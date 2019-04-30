#pragma once
#include <vector>
#include "simpleGeneticBot.h"

class population {
	int gen_number; // The generation we are on. Called in nextGeneration

public:
	vector<simpleGeneticBot> generation; // A list of genetic bots
	population(); // Empty contructor creates 100 empty simple genetic bots.
	void update(obstacle obs1); // Update each genetic bot in vector
	// vector<simpleGeneticBot> nextGeneration(); // Creates the next genration of genetic bots.
};