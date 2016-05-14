#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <fstream> 

class Dinosaur {
	int lastJumpDistance; 
	int qArray[55];
	int jumpProgress;
	std::fstream file; 
	bool isMax(int distance); 
public:
	Dinosaur(); 
	void initialize(); 
	void jump();
	int getHeight();
	bool isJumpNeeded(int distance);
	void jumpSuccess();
	void death(); 
};

#endif