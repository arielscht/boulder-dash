
#ifndef __BOULDERS__
#define __BOULDERS__

#include "../../loadables/sprites/sprites.h"
#include "../../utils/constants.h"
#include "../../utils/utils/utils.h"
#include "../rockford/rockford.h"
#include "../../loadables/audio/audio.h"

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