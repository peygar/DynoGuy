#include "dinosaur.h"
#include <iostream>
using namespace std; 

const int MAX_JUMP_HEIGHT = 4; 
const int MAX_JUMP_PROGRESS = MAX_JUMP_HEIGHT * 2;

Dinosaur::Dinosaur():lastJumpDistance(-1),jumpProgress(0){}

void Dinosaur::initialize()
{
	for(int i = 0; i < 55; i++)
	{
		qArray[i] = 0; 
	}
}

void Dinosaur::jump() {
	if(jumpProgress == 0) 
	{
		jumpProgress = 1;
	}
}

int Dinosaur::getHeight() {
	if (jumpProgress == 0 || jumpProgress > MAX_JUMP_PROGRESS)
	{
		jumpProgress = 0;
		return 0;
	}
	int height = jumpProgress < (MAX_JUMP_PROGRESS / 2 + 1) ? jumpProgress : MAX_JUMP_PROGRESS - jumpProgress;
	jumpProgress++;
	return height;
}

bool Dinosaur::isJumpNeeded(int distance)
{
	if(jumpProgress != 0)
	{
		return false;
	}
	if (isMax(distance))
	{
		lastJumpDistance = distance;
		return true; 
	}
	return false; 
}

bool Dinosaur::isMax(int distance)
{
	int current = qArray[distance];
	for(int i = 0; i < distance; i++)
	{
		if(current < qArray[i])
		{
			return false;
		} 
	}
	return true; 
}

void Dinosaur::jumpSuccess()
{
 	if (lastJumpDistance >= 0)
 	{
 		qArray[lastJumpDistance] += 10; 
 	} 
 	lastJumpDistance = -1; 
 	file.open("qarray.txt", fstream::out | fstream::trunc);
 	for (int i = 0; i < 55; ++i)
 	{
 		file << qArray[i] << ", ";
 	}
 	file << endl;
 	file.close();
}

void Dinosaur::death()
{
	if (lastJumpDistance >= 0)
		qArray[lastJumpDistance] -= 100;
}
