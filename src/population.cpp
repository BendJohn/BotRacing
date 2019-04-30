#include "population.h"

using namespace gameEngine;

population::population()
{
	for (size_t i = 0; i < 100; i++) {
		simpleGeneticBot gen0Bot = simpleGeneticBot();
		generation.push_back(gen0Bot);
	}
}

void population::update(obstacle obs1)
{
	for (size_t i = 0; i < 100; i++) {
		simpleGeneticBot &gen_bot = generation[i];
		ofVec2f top_corner = gen_bot.getTopCorner();
		ofVec2f size = gen_bot.getSize();
		if (shouldDelete(top_corner, size, obs1)) {
			gen_bot.setSize(0, 0);
			continue;
		}
		gen_bot.update();
		std::cout << "-----------" << i << "-----------" << std::endl;
	}
}