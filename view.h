#ifndef VIEW_H
#define VIEW_H

class View {
	char cells[10][60];

public: 
	void print();
	void notify(int row, int column, char state)
};

#endif