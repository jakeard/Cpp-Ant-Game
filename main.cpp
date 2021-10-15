#include <curses.h>
#include "director.h"
#include <iostream>;
using namespace std;

int main()
{
    // instance of Director class
    Director d;
    // run method execute in Director class
    int score = d.execute();
    // after game ends, close window
    endwin();
    // print what score they got
    cout << "\nYour score is: " << score << endl;
    return 0;
}