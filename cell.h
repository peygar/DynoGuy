#ifndef CELL_H
#define CELL_H

class Game; 

class Cell 
{
	int row;
	int column;
	char state;
	Game *currentGame;
	void notify(); 

public: 
	Cell(); 
	~Cell(); 
	void setState(char newState); 
	void setGame(Game *game);
	void setCoordinates(int newRow, int newColumn);

	// testing
	char getState() {return state;}
};

#endif