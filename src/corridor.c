#include <stdlib.h>
#include <stdbool.h>

#include "room.h"
#include "corridor.h"

#include "utilities.h"

int getEndXPos (Corridor *c) {

    if (c->dir == North || c->dir == South) return c->startXPos;
    else if (c->dir == East) return c->startXPos + c->length - 1;
    else return c->startXPos - c->length + 1;

}

int getEndYPos (Corridor *c) {

    if (c->dir == East || c->dir == West) return c->startYPos;
    else if (c->dir == North) return c->startYPos + c->length - 1;
    else return c->startYPos - c->length + 1;

}

Corridor *createCorridor (Room *room, unsigned int length,
    unsigned int mapWidth, unsigned int mapHeight, bool firstCorridor) {

    Corridor *c = (Corridor *) malloc (sizeof (Corridor *));

    c->dir = (Direction) randomInt (0, 3);

    Direction oppositeDir = (Direction) (((int) room->enteringCorridor + 2) % 4);

    if (!firstCorridor && c->dir == oppositeDir) {
        int dirInt = (int) c->dir;
        dirInt++;
        dirInt = dirInt % 4;
        c->dir = (Direction) dirInt;
    }

    // the lengths depends on the direction
    c->length = length;
    // FIXME: create a cap for the lenght
    int maxLength;

    switch (c->dir) {
        case North:
            c->startXPos = randomInt (room->xPos, room->xPos + room->width - 1);
            c->startYPos = room->yPos + room->height;
            maxLength = mapHeight - c->startYPos - MIN_ROOOM_HEIGHT;
            break;
        case East:
            c->startXPos = room->xPos + room->width;
            c->startYPos = randomInt (room->yPos, room->yPos + room->height - 1);
            maxLength = mapWidth - c->startXPos - MIN_ROOOM_WIDTH;
            break;
        case South:
            c->startXPos = randomInt (room->xPos, room->xPos + room->width);
            c->startYPos = room->yPos;
            maxLength = c->startYPos - MIN_ROOOM_HEIGHT;
            break;
        case West:
            c->startXPos = room->xPos;
            c->startYPos = randomInt (room->yPos, room->yPos + room->height);
            maxLength = c->startXPos - MIN_ROOOM_WIDTH;
            break;
    }

    c->length = clampInt (c->length, 1, maxLength);

    return c;

}