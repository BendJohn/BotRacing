#include "simpleGeneticBot.h"

simpleGeneticBot::simpleGeneticBot()
{
	ofVec2f v1;
	v1.set(100, ofGetWindowHeight() / 3);
	top_corner = v1;

	ofVec2f v2;
	v2.set(20, 20);
	boxsize = v2;
		
	for (size_t i = 0; i < 20; i++) {
		moves.push_back(UP);
	}
	for (size_t i = 0; i < 20; i++) {
		moves.push_back(RIGHT);
	}
}

simpleGeneticBot::simpleGeneticBot(ofVec2f v1, ofVec2f v2, vector<BotDirection> dirs)
{
	top_corner = v1;
	boxsize = v2;
	moves = dirs;
}

BotDirection simpleGeneticBot::chooseDirection()
{
	if (moves.size() > move_number) {
		return moves[move_number];
	}
	BotDirection random_dir = static_cast<BotDirection>(rand() % 4);
	return random_dir;
}

void simpleGeneticBot::update()
{
	BotDirection next_move = chooseDirection();
	if (boxsize.x != 0 && 5 + moves.size() >= move_number) {
		new_moves.push_back(next_move);
	}
	else {
		return;
	}

	if (new_moves.size() > move_number) {
		std::cout << new_moves[move_number] << std::endl;
	}

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
	move_number++;
}

ofVec2f simpleGeneticBot::getTopCorner()
{
	return top_corner;
}

ofVec2f simpleGeneticBot::getSize()
{
	return boxsize;
}

int simpleGeneticBot::getMoveNumber()
{
	return move_number;
}

int simpleGeneticBot::getFitness()
{
	return top_corner.x * top_corner.x - top_corner.y;
}

vector<BotDirection> simpleGeneticBot::getNewMoves()
{
	return new_moves;
}

void simpleGeneticBot::setSize(int a, int b)
{
	boxsize.set(a, b);
}