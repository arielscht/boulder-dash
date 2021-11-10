#include "sprites.h"

#ifndef __DIAMONDS__
#define __DIAMONDS__

typedef struct DIAMOND
{
    int x, y;
    bool shown;
} DIAMOND;

#endif

void diamond_draw(DIAMOND *diamonds, int diamondQuantity, SPRITES *sprites);