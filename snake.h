#pragma once
#include <vector>
using namespace std;
class Snake {
private:
	vector<char> body;

public:
	Snake();
	void addSegment();
	vector<char> getBody();
	int getSnakeSize();
};