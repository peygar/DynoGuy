#include "cell.h"
#include "game.h"

Cell::Cell():state('$'), currentGame(NULL)
{}

Cell::~Cell()
{}

void Cell::setState(char newState)
{
	state = newState; 
	notify(); 
}

void Cell::setGame(Game *game)
{
	currentGame = game; 
}

void Cell::setRow(int newRow)
{
	row = newRow; 
}

void Cell::setColumn(int newColumn)
{
	column = newColumn; 
}

void Cell::notify()
{
	currentGame->notify(row, column, state); 
}
