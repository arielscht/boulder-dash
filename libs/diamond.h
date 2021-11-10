#include "sprites.h"

#ifndef __DIAMONDS__
#define __DIAMONDS__

typedef struct DIAMOND
{
    int x, y;
    int sourceX, sourceY;
    int delay;
    bool shown;
} DIAMOND;

#endif

void diamond_update(DIAMOND *diamonds, int diamondQuantity);

void diamond_draw(DIAMOND *diamonds, int diamondQuantity, SPRITES *sprites);