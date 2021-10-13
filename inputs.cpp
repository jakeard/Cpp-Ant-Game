//#include <curses.h>
#include <conio.h>
#include <iostream>
#include <tuple>
#include "inputs.h"
using namespace std;

char Input::getInput() {
	int key = 0;
	char pressed = 'h';
	if (_kbhit()) {
		key = _getch();
	}
	switch (key) {
		case 119:
			pressed = 'w';
			break;
		case 97:
			pressed = 'a';
			break;
		case 115:
			pressed = 's';
			break;
		case 100:
			pressed = 'd';
			break;
	}
	return pressed;
}