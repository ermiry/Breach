#ifndef ROOM_H_
#define ROOM_H_

#include "corridor.h" 

typedef struct {

    // lower left tile of the room
    int xPos, yPos;

    unsigned int height;
    unsigned int width;

    Direction enteringCorridor;

} Room;

extern Room *createMainRoom (unsigned int, unsigned int);
extern Room *createRoom (unsigned int, unsigned int, Corridor *);

#endif 