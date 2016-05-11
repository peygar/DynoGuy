class Game
{
	Cell cells[10][60];
	Dinosaur *dino;
	View *view;

public:
	Game();
	void play(); //loop
	~Game();
};

class Cell {
	char state;
};

class View {
	char cells[10][60];
public:
	void print();
};

class Dinosaur {
	int distance;
	int qMatrix[10][10];
public:
	void jump();
	bool shouldJump();
};

Game::Game() {
	dino = new Dinosaur();
	view = new View();
}

Game::~Game() {
	delete dino;
	delete view;
}