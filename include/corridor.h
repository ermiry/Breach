#ifndef CORRIDOR_H_
#define CORRIDOR_H_

typedef enum { North, East, South, West } Direction;

typedef struct {

    int startXPos;
    int startYPos;
    unsigned int length;

    Direction dir;

} Corridor;

#endif 