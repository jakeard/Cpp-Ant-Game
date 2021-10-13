#pragma once
#include "inputs.h"
#include "snake.h"
class Director {
public:
	int updateMove(char key);
	//int doOutput();
	void doUpdate(Snake snake, char key);
	char getInput(Input inputs);
	void gameLoop();
	void execute();
};
