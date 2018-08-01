#ifndef CORRIDOR_H_
#define CORRIDOR_H_

#include "room.h"

typedef enum { North, East, South, West } Direction;

typedef struct Corridor {

    int startXPos;
    int startYPos;
    unsigned int length;

    Direction dir;

} Corridor;

extern int getEndXPos (Corridor *);
extern int getEndYPos (Corridor *);

// FIXME:
// extern Corridor *createCorridor (Room *, unsigned int);

#endif 