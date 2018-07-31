#include <stdlib.h>

#include "room.h"
#include "corridor.h"

#include "utilities.h"

// we create the other rooms based on this room
Room *createMainRoom (unsigned int mapWidth, unsigned int mapHeight) {

    Room *mainRoom = (Room *) malloc (sizeof (Room));

    mainRoom->height = randomInt (4, 8);
    mainRoom->width = randomInt (4, 8);

    // place it roughly in the middle of the map
    mainRoom->xPos = mapHeight / 2;
    mainRoom->yPos = mapWidth / 2;

    return mainRoom;

}

// creates a new room based on a corridor
Room *createRoom (unsigned int mapWidth, unsigned int mapHeight, Corridor *corridor) {



}