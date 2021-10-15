#include "food.h"
#include <stdlib.h>
#include <time.h>
// food class functions

Food::Food() {
	// construct food's visual and food's location vector
	food = '@';
	location.push_back(0);
}

vector<int> Food::getCoords() {
	// returns the vector of the foods coordinates
	return location;
}

const char Food::getFood() {
	// returns foods character
	return food;
}

void Food::newFood() {
	// creates a new food at the beginning of the game, or when the ant hits the old fruit
	location.clear();
	srand(time(NULL));
	int num = (rand() % 23) + 3;
	int num2 = (rand() % 110) + 3;
	location.push_back(num);
	location.push_back(num2);
}