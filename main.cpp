#include <curses.h>
#include "director.h"
//#include <conio.h>
using namespace std;

int main()
{
    // start window
    // PUT WINDOW IN OWN CLASS!!!!!!!!!!!!!!!!!!!!!!!!!
    auto scr = initscr();
    // print at coordinates y, x, string
    mvprintw(13, 50, "Welcome to Snake");
    mvprintw(15, 47, "Press any key to begin");
    // refresh the window to include the new print
    refresh();
    // wait for key press
    getch();
    clear();
    refresh();
    // instance of Director class
    Director d;
    // execute method execute in Director class
    d.execute();
    // after game ends, close window
    endwin();
    return 0;
}