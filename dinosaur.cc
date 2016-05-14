#include "dinosaur.h"

void Dinosaur::jump() {
	jumpProgress = 1;
}

int Dinosaur::getHeight() {
	if (jumpProgress == 0 || jumpProgress > 5)
	{
		jumpProgress = 0;
		return 0;
	}
	int height = jumpProgress < 4 ? jumpProgress - 1 : 5 - jumpProgress;
	jumpProgress++;
	return height;
}

