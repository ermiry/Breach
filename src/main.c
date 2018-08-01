#include "breach.h"

#include <time.h>

// FIXME: move these
Player *playerSetUp ();
void handleInput (int, Player *);

// TODO:  do we need a separte screen file??
void screenSetUp () {

    initscr ();
    printw ("Breach!!");
    noecho ();
    refresh ();

}

// FIXME: this is for testing
extern void generateMap ();

int main (void) {

    srand (time (NULL));

    screenSetUp ();

    generateMap ();

    Player *user = playerSetUp ();

    int ch;
    while ((ch = getch ()) != 'q')
        handleInput (ch, user);

    free (user);
    endwin ();

    return 0;

}