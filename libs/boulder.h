#include "sprites.h"

#ifndef __BOULDERS__
#define __BOULDERS__

typedef struct BOULDER
{
    int x, y;
} BOULDER;

#endif

void boulder_update(BOULDER *boulders, int boulderQuantity);

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites);