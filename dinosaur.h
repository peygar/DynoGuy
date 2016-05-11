#ifndef DINOSAUR_H
#define DINOSAUR_H

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

#endif