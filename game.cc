#include "game.h"
#include "cell.h"
#include "dinosaur.h"
#include "view.h"

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

Game::notify(int row, int column, char state)
{
	view->notify(row, column, state); 
}

Game::createCactus() {
	int height = rand() % (MAX_CACTUS_HEIGHT - MIN_CACTUS_HEIGHT + 1) + MIN_CACTUS_HEIGHT;
	Cacti->insert(0, pair<int, int>(59, height));

	for(int i = 0; i < height; i++)
	{
		cells[10 - i][59] = '#'; 
	} 
}

//TODO: MOVE CACTUS

Game::play() {
	srand(time(NULL));

	int distance = 0;
	while(1) {
		if (distance == 0)
		{
			distance = rand() % (MAX_CACTUS_DISTANCE - MIN_CACTUS_DISTANCE + 1) + MIN_CACTUS_DISTANCE;
			createCactus();
		}

		if (kbhit()) {
			dino->jump()
		}

		//move cacti
		dinoHeight = dino->getHeight();

		if (cacti->front.first == DINO_LOCATION && dinoHeight < cacti->front.second) {
			EndGame(); 
		}
	}
}
