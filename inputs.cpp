#include <conio.h>
#include <iostream>
#include <tuple>
#include <curses.h>
#include "inputs.h"
using namespace std;
// input class functions

char Input::getLastKey() {
	// returns the last key that was pressed
	return lastKey;
}

char Input::getInput() {
	// gets the ascii of the key pressed by the user, and returns the char of it
	char pressed;
	int key = _getch();
	flushinp();
	switch (key) {
		case 119:
			pressed = 'w';
			return pressed;
		case 97:
			pressed = 'a';
			return pressed;
		case 115:
			pressed = 's';
			return pressed;
		case 100:
			pressed = 'd';
			return pressed;
		default:
			return getLastKey();
	}
}

bool Input::keyPress() {
	// determines if a key has been pressed
	if (_kbhit()) {
		return true;
	}
	else {
		return false;
	}
}