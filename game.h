#ifndef GAME_H
#define GAME_H

class Cell; 
class Dinosaur;

#include <iostream> 
#include <vector> 
#include "cell.h"

class View;

typedef std::vector<std::pair<int,int> > Cacti;

class Game
{
	Cell cells[10][60]; 
	Cacti *cacti;
	Dinosaur *dino;
	View *view; 

	void initialize(); 
	void createCactus();
	void moveCactus(int location, int height);
	void moveCacti();

public:
	Game();
	void play(); //loop
	void notify(int row, int column, char state); 
	~Game();
};

#endif