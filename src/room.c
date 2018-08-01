#include <stdlib.h>

#include <ncurses.h>

#include "room.h"
#include "corridor.h"

#include "utilities.h"

// we create the other rooms based on this room
Room *createMainRoom (unsigned int mapWidth, unsigned int mapHeight) {

    Room *mainRoom = (Room *) malloc (sizeof (Room));

    mainRoom->height = randomInt (MIN_ROOOM_HEIGHT, 8);
    mainRoom->width = randomInt (MIN_ROOOM_WIDTH, 8);

    // place it roughly in the middle of the map
    mainRoom->xPos = (mapWidth / 2) - mainRoom->width;
    mainRoom->yPos = (mapHeight / 2) - mainRoom->height;

    return mainRoom;

}

// creates a new room based on a corridor that enters the room
Room *createRoom (unsigned int mapWidth, unsigned int mapHeight, Corridor *corridor) {

    Room *newRoom = (Room *) malloc (sizeof (Room));

    newRoom->width = randomInt (4, 8);
    newRoom->height = randomInt (4, 8);
    newRoom->enteringCorridor = corridor->dir;

    switch (newRoom->enteringCorridor) {
        case North: 
            newRoom->height = clampInt (newRoom->height, 4, mapHeight - getEndYPos (corridor));
            // the y coord of the room must be at the end of the corridor
            newRoom->yPos = getEndYPos (corridor);
            // get a random x pos but between a range
            newRoom->xPos = randomInt (getEndXPos (corridor) - newRoom->width + 1, getEndXPos (corridor));
            // make sure the room doesnt go off the map
            newRoom->xPos = clampInt (newRoom->xPos, 0, mapWidth - newRoom->width);
            break;
        case East:
            newRoom->xPos = getEndXPos (corridor);
            newRoom->yPos = randomInt (getEndYPos (corridor) - newRoom->height + 1, getEndYPos (corridor));
            newRoom->yPos = clampInt (newRoom->yPos, 0, mapHeight - newRoom->height);
            break;
        case South:
            newRoom->yPos = getEndYPos (corridor) - newRoom->height + 1;
            newRoom->xPos = randomInt (getEndXPos (corridor) - newRoom->width + 1, getEndXPos (corridor));
            newRoom->xPos = clampInt (newRoom->xPos, 0, mapWidth - newRoom->width);
            break;
        case West:
            newRoom->xPos = getEndXPos (corridor) - newRoom->width + 1;
            newRoom->yPos = randomInt (getEndYPos (corridor) - newRoom->height + 1, getEndYPos (corridor));
            newRoom->yPos = clampInt (newRoom->yPos, 0, mapHeight - newRoom->height);
            break;
    }

    return newRoom;

}

void drawRoom (Room *r) {

    // draw top & bottom
    for (unsigned int x = r->xPos; x <= r->xPos + r->width; x++) {
        mvprintw (r->yPos, x, "-");  // bottom
        mvprintw (r->yPos - r->height + 1, x, "_"); // top
    }

    for (unsigned int y = r->yPos - 1; y > r->yPos - r->height + 1; y--) {
        // draw walls
        mvprintw (y, r->xPos, "|");
        mvprintw (y, r->xPos + r->width, "|");

        // draw floor
        for (int x = r->xPos + 1; x < r->xPos + r->width; x++)
            mvprintw (y, x, ".");
    }

}