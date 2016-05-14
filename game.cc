#include "game.h"
#include "cell.h"
#include "dinosaur.h"
#include "view.h"

#include <iostream> 
#include <queue> 

using namespace std;

const int MAX_CACTUS_DISTANCE = 40;
const int MIN_CACTUS_DISTANCE = 3;
const int MAX_CACTUS_HEIGHT = 1;
const int MIN_CACTUS_HEIGHT = 1;
const int DINO_LOCATION = 5;

Game::Game() {
	dino = new Dinosaur();
	cacti = new Cacti;
	view = new View; 
}

Game::~Game() {
	delete dino;
	delete cacti;
	delete view; 
}

void Game::initialize()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 60; j++)
		{
			// cout << i <<  " " << j << endl;
			cells[i][j].setState(' ');
			notify(i, j, ' ');
		}
	}

	for(int i = 0; i < 60; i++)
	{
		cells[9][i].setState('_'); 
		notify(9, i, '_');
	}

	cells[9][DINO_LOCATION].setState('*'); 

	notify(9, DINO_LOCATION, '*'); 
}

void Game::notify(int row, int column, char state)
{
	view->notify(row, column, state); 
}

void Game::createCactus() 
{
	int height = rand() % (MAX_CACTUS_HEIGHT - MIN_CACTUS_HEIGHT + 1) + MIN_CACTUS_HEIGHT;
	cacti->insert(cacti->begin(), pair<int, int>(59, height));

	for(int i = 0; i < height; i++)
	{
		cells[9 - i][59].setState('#'); 
	} 
}

void Game::moveCactus(int location, int height)
{
	for(int i = 0; i <= height; i++)
	{
		if (i == 0)
		{
			cells[i][location].setState('_');
		}

		else
		{
			cells[i][location].setState(' ');
		}

		if (location > 0)
		{
			cells[i][location - 1].setState('O');
		}
	}
}

void Game::moveCacti()
{
	for(vector<pair<int, int> >::iterator it = cacti->begin(); it != cacti->end(); ++it)
	{
		moveCactus(it->first, it->second);
		it->first--; 
	}

	if(cacti->back().first == -1)
	{
		cacti->pop_back(); 
	}
}

//TODO: MOVE CACTUS

void Game::play() {

	srand(time(NULL));
	
	initialize();
	
	int distance = 0;
	while(1) {
		if (distance == 0)
		{
			distance = rand() % (MAX_CACTUS_DISTANCE - MIN_CACTUS_DISTANCE + 1) + MIN_CACTUS_DISTANCE;
			createCactus();
		}

		// if (kbhit()) {
		// 	dino->jump();
		// }

		moveCacti(); 

		int dinoHeight = dino->getHeight();

		if (cacti->front().first == DINO_LOCATION && dinoHeight < cacti->front().second) {
			// EndGame(); 
		}
		view->print();
	}
	
}
