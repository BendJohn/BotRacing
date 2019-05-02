#pragma once
#include <vector>
#include "simpleGeneticBot.h"

class population {
	int gen_number; // The generation we are on. Called in nextGeneration
	int round; // Keeps track of the round we are on

public:
	vector<simpleGeneticBot> generation; // A list of genetic bots
	population(); // Empty contructor creates 100 empty simple genetic bots.
	void update(obstacle obs1); // Update each genetic bot in vector
	vector<simpleGeneticBot> sortByFitness(); // Sorts the generation vector by fitness.
	void nextGeneration(); // Creates the next genration of genetic bots.
	int getGen_number(); // Gets the generation number
	int getRound(); // Gets the round number
};