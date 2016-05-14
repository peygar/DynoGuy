#include "view.h"
#include <iostream>

using namespace std;

void View::print() {
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			cout << cells[i][j];
		}
		cout << endl;
	}
}

void View::notify(int row, int column, char state) {
	cells[row][column] = state;
}