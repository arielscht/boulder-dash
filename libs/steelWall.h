#ifndef __STEEL_WALLS__
#define __STEEL_WALLS__

#include "sprites.h"

typedef struct STEEL_WALL
{
    int x, y;
} STEEL_WALL;

void steel_wall_draw(STEEL_WALL *walls, int wallQuantity, SPRITES *sprites);

#endif