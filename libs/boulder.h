
#ifndef __BOULDERS__
#define __BOULDERS__

#include "sprites.h"
#include "constants.h"
#include "utils.h"
#include "rockford.h"
#include "audio.h"

typedef struct BOULDER
{
    int x, y;
    int delay;
    bool falling;
    int pushed;
    bool shown;
} BOULDER;

void boulder_update(
    BOULDER *boulders,
    int boulderQuantity,
    ROCKFORD *player,
    char map[MAP_HEIGHT][MAP_WIDTH],
    SOUNDS *sounds);

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites);

#endif