#ifndef __WALLS__
#define __WALLS__

#include "sprites.h"
#include "constants.h"
#include "utils.h"
typedef struct WALL
{
    int x, y;
    bool shown;
} WALL;

void wall_update(WALL *walls, int wallsQuantity, char map[MAP_HEIGHT][MAP_WIDTH]);
void wall_draw(WALL *walls, int wallsQuantity, SPRITES *sprites);
#endif