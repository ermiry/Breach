// © Copy Erick Salas 2018 

#ifndef BREACH_H_
#define BREACH_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

// TODO: more likely we are going to move this data structs to their own sperate files
typedef struct {

    int xPos;
    int yPos;
    unsigned int health;

} Player;



#endif 