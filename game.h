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

	void initialize(); 
	void createCactus();
	void moveCactus(int location, int height);
	void moveCacti();

public:
	Game();
	void play(); //loop
	void notify(int row, int column, int state); 
	~Game();
};

#endif