#ifndef ROOM_H_
#define ROOM_H_

#include "corridor.h"

#define MIN_ROOOM_HEIGHT 4
#define MIN_ROOOM_WIDTH 4

typedef struct Room {

    // lower left tile of the room
    unsigned int xPos, yPos;

    unsigned int height;
    unsigned int width;

    Direction enteringCorridor;

} Room;

extern Room *createMainRoom (unsigned int, unsigned int);
extern Room *createRoom (unsigned int, unsigned int, Corridor *);

extern void drawRoom (Room *);

#endif 