#pragma once
#include <vector>
using namespace std;

class Food {
	// food class header file
private:
	char food;
	vector<int> location;
public:
	Food();
	const char getFood();
	vector<int> getCoords();
	void newFood();
};