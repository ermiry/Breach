#include "breach.h"

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

// check if the player is allowed to move to the new pos
void handleCollisions (int newY, int newX, Player *user) {

    int space;
    switch (mvinch (newY, newX)) {
        case '.': movePlayer (newY, newX, user); break;
        default: move (user->yPos, user->xPos); break;
    }

}

void handleInput (int input, Player *user) {

    int newY, newX;

    switch (input) {
        case 'w':
            newY = user->yPos - 1;
            newX = user->xPos;
            break;
        case 'a':
            newY = user->yPos;
            newX = user->xPos - 1;
            break;
        case 's':
            newY = user->yPos + 1;
            newX = user->xPos;
            break;
        case 'd':
            newY = user->yPos;
            newX = user->xPos + 1;
            break;
        default: break;
    }

    handleCollisions (newY, newX, user);

}