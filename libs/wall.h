#ifndef __WALLS__
#define __WALLS__

#include "sprites.h"

typedef struct WALL
{
    int x, y;
    bool shown;
} WALL;

void wall_draw(WALL *walls, int wallsQuantity, SPRITES *sprites);
#endif