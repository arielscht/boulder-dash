#ifndef __DIRTS__
#define __DIRTS__

#include <stdio.h>
#include "../../loadables/sprites/sprites.h"
#include "../rockford/rockford.h"
#include "../../utils/constants.h"
#include "../../loadables/audio/audio.h"
#include "../../utils/utils/utils.h"

typedef struct DIRT
{
    int x, y;
    bool shown;
} DIRT;

void dirt_update(DIRT *dirts,
                 int dirtQuantity,
                 ROCKFORD *player,
                 char map[MAP_HEIGHT][MAP_WIDTH],
                 SOUNDS *sounds);

void dirt_draw(DIRT *dirts, int dirtQuantity, SPRITES *sprites);

#endif