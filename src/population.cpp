#include "population.h"

using namespace gameEngine;

int kNumberOfBots = 100;
int kNumberOfNewMoves = 10;

population::population()
{
	for (size_t i = 0; i < kNumberOfBots; i++) {
		simpleGeneticBot gen0Bot = simpleGeneticBot();
		generation.push_back(gen0Bot);
	}
}

void population::update(obstacle obs1)
{
	/*for (size_t i = 0; i < 10; i++) {
		simpleGeneticBot &gen_bot = generation[i];
		ofVec2f top_corner = gen_bot.getTopCorner();
		ofVec2f size = gen_bot.getSize();
		if (shouldDelete(top_corner, size, obs1)) {
			gen_bot.setSize(0, 0);
			continue;
		}
		gen_bot.update();
		std::cout << "-----------" << i << "-----------" << std::endl;
	}*/
	round++;
	std::cout << "Round: " << round << std::endl;
	std::cout << "Generation: " << gen_number << std::endl;
	if (round >= kNumberOfNewMoves * (gen_number + 1)) {
		nextGeneration();
	}
}

vector<simpleGeneticBot> population::sortByFitness()
{
	vector<simpleGeneticBot> fit_bots;
	for (size_t i = 0; i < generation.size() / 2; i++) {
		int max_i = 0;
		int max_fitness = 0;
		for (size_t j = 0; j < generation.size(); j++) {
			simpleGeneticBot& genBot = generation[j];
			int fitness = genBot.getFitness();
			ofVec2f size = genBot.getSize();
			if (fitness > max_fitness && size.x != 0) {
				max_fitness = fitness;
				max_i = j;
			}
		}
		simpleGeneticBot& fitBot = generation[max_i];
		fit_bots.push_back(fitBot);
		fitBot.setSize(0, 0);
	}
	return fit_bots;
}

void population::nextGeneration()
{
	vector<simpleGeneticBot> fit_bots = sortByFitness();
	generation.clear();
	for (size_t i = 0; i < fit_bots.size(); i++) {
		simpleGeneticBot& prevGenBot = fit_bots[i];
		vector<BotDirection> dirs = prevGenBot.getNewMoves();
		simpleGeneticBot genBot = simpleGeneticBot(dirs);
		generation.push_back(genBot);
		generation.push_back(genBot);
	}
	gen_number++;
	round = 0;
}