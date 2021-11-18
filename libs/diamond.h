#ifndef __DIAMONDS__
#define __DIAMONDS__

#include "sprites.h"
#include "constants.h"

typedef struct DIAMOND
{
    int x, y;
    int sourceX, sourceY;
    int delay;
    bool shown, falling;
} DIAMOND;

void diamond_update(DIAMOND *diamonds, int diamondQuantity, char map[MAP_HEIGHT][MAP_WIDTH]);

void diamond_draw(DIAMOND *diamonds, int diamondQuantity, SPRITES *sprites);

#endif