#include "sprites.h"

#ifndef __STEEL_WALLS__
#define __STEEL_WALLS__

typedef struct STEEL_WALL
{
    int x, y;
} STEEL_WALL;

#endif

void steel_wall_draw(STEEL_WALL *walls, int wallQuantity, SPRITES *sprites);