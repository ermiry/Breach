// This is our map controller
// It will take care of setting up the rooms and everything else.

// 31/07/2018 --- For now we will generate a simple map that only contains rooms
// like a dungeon. Later on we will want to create a more complex map.

#include <stdlib.h>
#include <stdbool.h>

#include "room.h"
#include "corridor.h"

#include "utilities.h"

typedef enum { Floor, Wall } TileType;

// TODO: do we want to have a coordinate system?? using a coord struct?

// TODO: is it a good idea to have tiletypes??

// TODO: do we want to have a variable map size?
// we are taking into account that each space in the terminal is like a tile
// so we have a ratio of 1:1
// FIXME: how to setup to a fixed terminal size we want??? 

// TODO: for now this is only for testing, later we will want to have varibale number of rooms
unsigned int numRooms = 4;


// lets try thius to solve our references problems
typedef struct {
    
    unsigned int height;
    unsigned int width;

    // TODO: we eill test if this is the best way to instantiate floors and walls
    // unsigned int **tiles;

    Room **rooms;
    Corridor **corridors;

} Map;

// FIXME:
Corridor *createCorridor (Room *, unsigned int, unsigned int, unsigned int, bool);

// Generates the rooms and connects them with corridors
void generateRoomsAndCorridors (Map *map) {

    // create the main room
    map->rooms[0] = createMainRoom (map->width, map->height);

    // create the first corridor using the main room
    // FIXME: 
    map->corridors[0] = createCorridor (map->rooms[0], randomInt (6, 10), map->width, map->height, true);

    // setup the other rooms
    for (int i = 1; i < numRooms; i++) {
        map->rooms[i] = createRoom (map->width, map->height, map->corridors[i - 1]);
        // if we haven't created all the corridors
        if (i < (numRooms - 1)) 
            map->corridors[i] = createCorridor (map->rooms[i], randomInt (6, 10), map->width, map->height, false);  // FIXME:
        
    }

}

/* void setTilesValuesForRooms (Map *map) {

    for (unsigned int i = 0; i < numRooms; i++) {
        for (unsigned int x = 0; x < map->rooms[i]->width; x++) {
            unsigned int xCoord = map->rooms[i]->xPos + x;
            for (unsigned int y = 0; y < map->rooms[i]->height; y++) {
                unsigned int yCoord = map->rooms[i]->yPos + y;
                
                // FIXME: 1 is for floors
                map->tiles[xCoord][yCoord] = 1;
            }
        }
 
    }

}

void setTilesValuesForCorridors (Map *map) {

    for (unsigned int i = 0; i < numRooms - 1; i++) {
        for (unsigned int x = 0; x < map->corridors[i]->length; x++) {
            unsigned int xCoord = map->corridors[i]->startXPos;
            unsigned int yCoord = map->corridors[i]->startYPos;

            switch (map->corridors[i]->dir) {
                case North: yCoord += x; break;
                case East: xCoord += x; break;
                case South: yCoord -= x; break;
                case West: xCoord -= x; break;
            }
            
            // FIXME: 1 is for floors
            map->tiles[xCoord][yCoord] = 1;
        }
    }

} */

// TODO: where and how do we spawn the player??
// Main Thread of the map generation
void generateMap () {

    Map *map = (Map *) malloc (sizeof (Map));

    // We are testing with a 16:9 ratio
    // map->width = 54;
    // map->height = 96;

    map->width = 80;
    map->height = 30;

    // map->tiles = (unsigned int **) malloc (map->width * sizeof (unsigned int *));
    // for (int i = 0; i < map->width; i++)
    //     map->tiles[i] = (unsigned int *) malloc (map->height * sizeof (unsigned int));

    map->rooms = (Room **) calloc (numRooms, sizeof (Room *));
    // lets see how it goes having a corridor less than the number rooms
    map->corridors = (Corridor **) calloc (numRooms - 1, sizeof (Corridor *));

    generateRoomsAndCorridors (map);

    // setTilesValuesForRooms (map);

    // setTilesValuesForCorridors (map);

    // Draw the rooms
    for (unsigned int i = 0; i < numRooms; i++)
        drawRoom (map->rooms[i]);

    // Draw the corridors
    for (unsigned int i = 0; i < numRooms - 1; i++) 
        drawCorridor (map->corridors[i]);

}

