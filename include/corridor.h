#ifndef CORRIDOR_H_
#define CORRIDOR_H_

typedef enum { North, East, South, West } Direction;

typedef struct {

    int startXPos;
    int startYPos;
    unsigned int length;

    Direction dir;

} Corridor;

extern int getEndXPos (Corridor *);
extern int getEndYPos (Corridor *);

extern Corridor *createCorridor (Room *, unsigned int);

#endif 