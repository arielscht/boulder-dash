#ifndef __FIREFLY__
#define __FIREFLY__

#include "../../utils/constants.h"
#include "../../loadables/sprites/sprites.h"

typedef struct FIREFLY
{
    int x, y;
    int sourceX, sourceY;
    int delay;
    bool shown, exploded;
} FIREFLY;

void firefly_update(FIREFLY *fireflies, int fireflyQtd, char map[MAP_HEIGHT][MAP_WIDTH]);

void firefly_draw(FIREFLY *fireflies, int fireflyQtd, SPRITES *sprites);

#endif