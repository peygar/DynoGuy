/*class Game
{
	Cell cells[10][60]; 
	Cacti *cacti;

	Dinosaur *dino;

public:
	Game();
	void play(); //loop
	~Game();
};

class Cell {
	char state;
	Game *currentGame; 
public: 
	void setState(char newState); 
};

class View {
	char cells[10][60];
	void print();
};

class Dinosaur {
	int distance;
	int qMatrix[10][10];
	int jumpProgress;
public:
	void jump();
	bool shouldJump();
	int getHeight();
	void jumpIfNeed();
};

const int MAX_CACTUS_DISTANCE = 40;
const int MIN_CACTUS_DISTANCE = 3;
const int MAX_CACTUS_HEIGHT = 1;
const int MIN_CACTUS_HEIGHT = 1;
const int DINO_LOCATION = 5;
typedef std::vector<pair<int,int> > Cacti;

Game::Game() {
	dino = new Dinosaur();
	cacti = new Cacti;
}

Game::~Game() {
	delete dino;
	delete cacti;
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
*/