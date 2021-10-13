#include <iostream>
#include <string>
#include <curses.h>
#include <Windows.h>
#include "director.h"
using namespace std;


int Director::updateMove(char key) {
    switch (key) {
        case 'w':
            break;
        case 'a':
            break;
        case 's':
            break;
        case 'd':
            break;
    }
}
//void Director::doOutput() {
//
//}
//



void Director::doUpdate(Snake snake, char key) {
    vector<char> snakeBody = snake.getBody();
    if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
        updateMove(key);
    }
    

    /*for (int i = 0; i <= )*/
    /*for (int i = 5; i <= 115; i++) {
        mvprintw(20, i, "####8");
        refresh();
        Sleep(100);
        clear();
        refresh();
    }*/
}

char Director::getInput(Input inputs) {
    char key = inputs.getInput();
    return key;
}

void Director::gameLoop() {
    bool gameOver = false;
    Snake snake;
    Input input_service;
    while (gameOver == false) {
        char key = getInput(input_service);
        doUpdate(snake, key);
    }
}


void Director::execute() {
    gameLoop();
}
