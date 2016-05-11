#ifndef GAME_H
#define GAME_H

class Cell; 
class Dinosaur;

typedef std::vector<pair<int,int> > Cacti;

class Game
{
	Cell cells[10][60]; 
	Cacti *cacti;
	Dinosaur *dino;
	View *view; 

public:
	Game();
	void play(); //loop
	void notify(int row, int column, int state); 
	~Game();
};

#endif