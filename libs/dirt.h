#ifndef __DIRTS__
#define __DIRTS__

#include <stdio.h>
#include "sprites.h"

typedef struct DIRT
{
    int x, y;
    bool shown;
} DIRT;

void dirt_draw(DIRT *dirts, int dirtQuantity, SPRITES *sprites);

#endif