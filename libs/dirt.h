#include "sprites.h"

#ifndef __DIRTS__
#define __DIRTS__

typedef struct DIRT
{
    int x, y;
    bool shown;
} DIRT;

#endif

void dirt_draw(DIRT *dirts, int dirtQuantity, SPRITES *sprites);