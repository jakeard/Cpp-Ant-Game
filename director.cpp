#include <iostream>
#include <string>
#include <curses.h>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include "director.h"
#include "screen.h"
using namespace std;

void Director::updateFood(int y, int x) {
    // check if ant collides with food. If no, do not move food. If yes, move food and add 1 to score
    vector<int> coords = food.getCoords();
    if (y == coords[0] && x == coords[1] + 1) {
        score++;
        food.newFood();
    }
    mvaddch(coords[0], coords[1], food.getFood());
    move(y, x);
    refresh();
}

void Director::updateMove(char key, Input inputs) {
    // updates the ant's position based on input
    const char antBody = ant.getBody();
    int x;
    int y;
    int wait = 0;
    while (!inputs.keyPress()) {
        y = getcury(curscr);
        x = getcurx(curscr);
        // if ant hits wall, turn it the opposite direction
        if (y == 0) {
            key = 's';
        }
        else if (y == 29) {
            key = 'w';
        }
        else if (x - 1 == 0) {
            key = 'd';
        }
        else if (x - 1 == 118){
            key = 'a';
        }

        // do something based on which key was pressed
        switch (key) {
        case 'w':
            mvaddch(y - 1, x - 1, antBody);
            wait = 50;
            break;
        case 'a':
            mvaddch(y, x - 2, antBody);
            wait = 20;
            break;
        case 's':
            mvaddch(y + 1, x - 1, antBody);
            wait = 50;
            break;
        case 'd':
            mvaddch(y, x, antBody);
            wait = 20;
            break;
        }
        refresh();
        // food check function
        updateFood(getcury(curscr), getcurx(curscr));
        Sleep(wait);
        clear();
        waited += wait;
    }
}

void Director::doUpdate(char key, Input inputs) {
    // calls update functions
    updateMove(key, inputs);
}

char Director::getInput(Input inputs) {
    // function to get and return user input
    char key = inputs.getInput();
    return key;
}

void Director::updateFile() {
    // function to update the file with new highscore
    ofstream file;
    file.open("highscore.txt");
    file << score;
    file.close();
}

void Director::gameLoop() {
    // initiate input class
    Input input_service;
    // create a new food
    food.newFood();
    // game timer (not perfect, but not terrible)
    while (waited < 20000) {
        // get user input
        char key = getInput(input_service);
        // update screen according to user input
        doUpdate(key, input_service);
    }
    // open highscore file and write the new highscore to it, if it is higher than the previous highscore
    string line;
    ifstream file("highscore.txt");
    while (getline (file, line)) {
        if (stoi(line) < score) {
            file.close();
            updateFile();
        }
    }
    mvprintw(13, 52, "Time is up!");
    refresh();
    Sleep(2000);
    clear();
}


int Director::execute() {
    // initiate screen
    Screen screen;
    string line;
    // read file and display highscore
    ifstream file("highscore.txt");
    while (getline (file, line)) {
        for (int i = 0; i < line.size(); i++) {
            char highscore = line[i];
            mvaddch(0, 12 + i, highscore);
        }
    }
    file.close();
    // print at coordinates y, x, string
    curs_set(0);
    mvprintw(0, 1, "Highscore: ");
    mvprintw(11, 50, "Welcome to Ant");
    mvprintw(13, 29, "You have about 30 seconds to eat as much fruit as possible");
    mvprintw(15, 45, "Press any key to begin");
    // refresh the window to include the new print
    refresh();
    // start game 
    gameLoop();
    // return the score to display to the user and store in a file.
    return score;
}
