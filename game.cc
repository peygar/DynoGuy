#include "game.h"
#include "cell.h"
#include "dinosaur.h"
#include "view.h"

#include <iostream> 
#include <queue> 
#include <unistd.h>
#include <sys/select.h>

using namespace std;

const int MAX_CACTUS_DISTANCE = 40;
const int MIN_CACTUS_DISTANCE = 3;
const int MAX_CACTUS_HEIGHT = 3;
const int MIN_CACTUS_HEIGHT = 1;
const int DINO_LOCATION = 5;
const int MAX_JUMP_HEIGHT = 6; 

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
			cells[i][j].setGame(this); 
			cells[i][j].setCoordinates(i, j);
			cells[i][j].setState(' ');
		}
	}

	for(int i = 0; i < 60; i++)
	{
		cells[9][i].setGame(this); 
		cells[9][i].setCoordinates(9, i); 
		cells[9][i].setState('_');	}

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
	for(int i = 0; i < height; i++)
	{
		if (i == 0)
		{
			cells[9 - i][location].setState('_');
		}

		else
		{
			cells[9 - i][location].setState(' ');
		}

		if (location > 0)
		{
			cells[9 - i][location - 1].setState('#');
		}
	}
}

void Game::moveCacti()
{
	for(vector<pair<int, int> >::iterator it = cacti->begin(); it != cacti->end(); ++it)
	{
		//cout << it->first << " " << it->second; 
		moveCactus(it->first, it->second);
		it->first--; 
	}

	if(cacti->back().first == -1)
	{
		cacti->pop_back(); 
		numberOfCactiPassed--;
	}
}

void Game::setDinoJump(int height)
{
	for (int i = 1; i < MAX_JUMP_HEIGHT; i++)
	{
		cells[9 - i][DINO_LOCATION].setState(' ');
	}
	cells[9][DINO_LOCATION].setState('_'); 

	cells[9 - height][DINO_LOCATION].setState('*'); 
}

//TODO: MOVE CACTUS

void Game::play() {

	srand(time(NULL));
	
	initialize();
	dino->initialize(); 
	
	int distance = 0;
	unsigned int sleepTime = 0;

	numberOfCactiPassed = 0;

	while(1) {
		if (distance == 0)
		{
			distance = rand() % (MAX_CACTUS_DISTANCE - MIN_CACTUS_DISTANCE + 1) + MIN_CACTUS_DISTANCE;
			createCactus();
		}
		else
		{
			distance--; 
		}

		pair<int, int> closestCactus = cacti->at(cacti->size() - numberOfCactiPassed - 1);

		if (dino->isJumpNeeded(closestCactus.first - DINO_LOCATION - 1)) {
			dino->jump();
		}

		int dinoHeight = dino->getHeight();

		setDinoJump(dinoHeight); 

		moveCacti();

		closestCactus = cacti->at(cacti->size() - numberOfCactiPassed - 1);

		if (cacti->size() != 0 && closestCactus.first == DINO_LOCATION) 
		{ 
			if(dinoHeight < closestCactus.second) 
			{
				endGame(); 
				numberOfCactiPassed++;
				dino->death(); 
				cout << "DIED" << endl; 
				// view->print();
				// return; 
			} 
			else 
			{
				numberOfCactiPassed++;
				dino->jumpSuccess(); 
				cout << "SUCCESS" << endl; 
			}
		}
		view->print();
		usleep(sleepTime); 
	}	
}

void Game::endGame()
{
	cells[9][DINO_LOCATION].setState('@'); 
}