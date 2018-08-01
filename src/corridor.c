#include "room.h"
#include "corridor.h"

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

// FIXME: setup other parameters
Corridor *createCorridor (Room *room, unsigned int length) {

    

}