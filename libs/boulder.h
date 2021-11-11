
#ifndef __BOULDERS__
#define __BOULDERS__

#include "sprites.h"

typedef struct BOULDER
{
    int x, y;
} BOULDER;

void boulder_update(BOULDER *boulders, int boulderQuantity);

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites);

#endif