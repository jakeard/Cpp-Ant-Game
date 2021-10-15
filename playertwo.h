#pragma once
#include <vector>
using namespace std;
class PlayerTwo {
private:
	vector<char> body;

public:
	PlayerTwo();
	void addSegment();
	vector<char> getBody();
	int getSnakeSize();
};

