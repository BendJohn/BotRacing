#include "simpleGeneticBot.h"

int kNumberOfMoves = 10;

simpleGeneticBot::simpleGeneticBot()
{
	ofVec2f v1;
	v1.set(100, ofGetWindowHeight() / 3);
	top_corner = v1;

	ofVec2f v2;
	v2.set(20, 20);
	boxsize = v2;

	move_number = 0;
}

simpleGeneticBot::simpleGeneticBot(vector<BotDirection> dirs)
{
	ofVec2f v1;
	v1.set(100, ofGetWindowHeight() / 3);
	top_corner = v1;

	ofVec2f v2;
	v2.set(20, 20);
	boxsize = v2;

	move_number = 0;

	moves = dirs;
}

/*simpleGeneticBot::simpleGeneticBot(simpleGeneticBot & copy_obj)
{
	this.top_corner = copy_obj.top_corner;
	this.boxsize = copy_obj.boxsize;
	this.move_number = copy_obj.move_number;
	this.moves = copy_obj.moves;
	this.new_moves = copy_obj.new_moves;

}*/

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
	if (boxsize.x != 0 && kNumberOfMoves + moves.size() >= move_number) {
		new_moves.push_back(next_move);
	}
	else {
		return;
	}

	/*if (new_moves.size() > move_number) {
		std::cout << new_moves[move_number] << " for move " << move_number << std::endl;
	}*/

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
	return (top_corner.x * top_corner.x - top_corner.y * top_corner.x) * boxsize.x;
}

vector<BotDirection> simpleGeneticBot::getNewMoves()
{
	return new_moves;
}

void simpleGeneticBot::setSize(int a, int b)
{
	boxsize.set(a, b);
}