
#ifndef __BOULDERS__
#define __BOULDERS__

#include "sprites.h"
#include "constants.h"
#include "utils.h"

typedef struct BOULDER
{
    int x, y;
    int delay;
    bool falling;
} BOULDER;

void boulder_update(BOULDER *boulders, int boulderQuantity, char map[MAP_HEIGHT][MAP_WIDTH]);

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites);

#endif