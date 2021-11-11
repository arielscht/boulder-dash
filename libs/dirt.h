#ifndef __DIRTS__
#define __DIRTS__

#include <stdio.h>
#include "sprites.h"
#include "rockford.h"
#include "constants.h"

typedef struct DIRT
{
    int x, y;
    bool shown;
} DIRT;

void dirt_update(DIRT *dirts, int dirtQuantity, ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH]);

void dirt_draw(DIRT *dirts, int dirtQuantity, SPRITES *sprites);

#endif