#include "sprites.h"

#ifndef __WALLS__
#define __WALLS__

typedef struct WALL
{
    int x, y;
    bool shown;
} WALL;

#endif

void wall_draw(WALL *walls, int wallsQuantity, SPRITES *sprites);