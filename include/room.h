#ifndef ROOM_H_
#define ROOM_H_

typedef struct {

    // lower left tile of the room
    int xPos, yPos;

    unsigned int height;
    unsigned int width;

    // TODO: corridors info here??

} Room;

#endif 