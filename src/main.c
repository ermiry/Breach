#include "breach.h"

typedef struct {

    int xPos;
    int yPos;
    unsigned int health;

} Player;

Player *playerSetUp () {

    Player *newPlayer = (Player *) malloc (sizeof (Player));

    newPlayer->xPos = 12;
    newPlayer->yPos = 12;
    newPlayer->health = 10;

    mvprintw (newPlayer->yPos, newPlayer->xPos, "@");
    move (newPlayer->yPos, newPlayer->xPos);

    return newPlayer;

}

void movePlayer (int y, int x, Player *user) {

    mvprintw (user->yPos, user->xPos, ".");

    user->yPos = y;
    user->xPos = x;

    mvprintw (user->yPos, user->xPos, "@");
    move (user->yPos, user->xPos);

}

void handleInput (int input, Player *user) {

    switch (input) {
        case 'w': movePlayer (user->yPos - 1, user->xPos, user); break;
        case 'a': movePlayer (user->yPos, user->xPos - 1, user); break;
        case 's': movePlayer (user->yPos + 1, user->xPos, user); break;
        case 'd': movePlayer (user->yPos, user->xPos + 1, user); break;
        default: break;
    }

}

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