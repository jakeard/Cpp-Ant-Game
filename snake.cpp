#include "snake.h"

Snake::Snake() {
	body.push_back('8');
	body.push_back('#');
}

void Snake::addSegment() {
	body.push_back('#');
}

vector<char> Snake::getBody() {
	return body;
}

int Snake::getSnakeSize() {
	return body.size();
}

