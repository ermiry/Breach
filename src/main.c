#include "breach.h"

// FIXME: move these
Player *playerSetUp ();
void handleInput (int, Player *);

void screenSetUp () {

    initscr ();
    printw ("Breach!!");
    noecho ();
    refresh ();

}

void mapSetUp () {

    mvprintw (10, 10, "----------");
    mvprintw (11, 10, "|........|");
    mvprintw (12, 10, "|........|");
    mvprintw (13, 10, "|........|");
    mvprintw (14, 10, "|........|");
    mvprintw (15, 10, "----------");

}

int main (void) {

    screenSetUp ();

    mapSetUp ();

    Player *user = playerSetUp ();

    int ch;
    while ((ch = getch ()) != 'q') {
        handleInput (ch, user);
    }


    free (user);
    endwin ();

    return 0;

}