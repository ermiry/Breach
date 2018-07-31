// This is our map controller
// It will take care of setting up the rooms and everything else.

// 31/07/2018 --- For now we will generate a simple map that only contains rooms
// like a dungeon. Later on we will want to create a more complex map.

#include <stdlib.h>

#include "room.h"
#include "corridor.h"

// TODO: do we want to have a coordinate system?? using a coord struct?

// TODO: is it a good idea to have tiletypes??

// TODO: do we want to have a variable map size?
// we are taking into account that each space in the terminal is like a tile
// so we have a ratio of 1:1
// FIXME: how to setup to a fixed terminal size we want??? 

// TODO: for now this is only for testing, later we will want to have varibale number of rooms
unsigned int numRooms = 4;

// FIXME: this shouldn't go here!! You are not in OOP!!
// unsigned int roomWidth = randomInt (4, 8);
// unsigned int roomHeight = randomInt (4, 8)

// lets try thius to solve our references problems
typedef struct {
    
    unsigned int height;
    unsigned int width;

    Room **rooms;
    Corridor **corridors;

} Map;

// Connect the rooms using the corridors
void connectRooms () {


}

// Main Thread of the map generation
void generateMap () {

    Map *map = (Map *) malloc (sizeof (Map));

    // TODO: do we need a tile array for tiletypes??

    map->rooms = (Room **) calloc (numRooms, sizeof (Room *));
    // lets see how it goes having a corridor less than the number rooms
    map->corridors = (Corridor **) calloc (numRooms - 1, sizeof (Corridor *));

    connectRooms (map);

}

