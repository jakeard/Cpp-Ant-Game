#pragma once
#include "inputs.h"
#include "ant.h"
#include "screen.h"
#include "food.h"

class Director {
	// director class header file
private:
	Ant ant;
	Food food;
	int waited = 0;
	int score = 0;
public:
	void updateFood(int y, int x);
	void updateMove(char key, Input inputs);
	void doUpdate(char key, Input inputs);
	char getInput(Input inputs);
	void updateFile();
	void gameLoop();
	int execute();
};
