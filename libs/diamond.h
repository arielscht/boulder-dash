#ifndef __DIAMONDS__
#define __DIAMONDS__

#include "sprites.h"
#include "constants.h"
#include "rockford.h"
#include "audio.h"

typedef struct DIAMOND
{
    int x, y;
    int sourceX, sourceY;
    int delay;
    bool shown, falling;
} DIAMOND;

void diamond_update(DIAMOND *diamonds,
                    int diamondQuantity,
                    ROCKFORD *player,
                    char map[MAP_HEIGHT][MAP_WIDTH],
                    MAP_DATA *mapData,
                    SOUNDS *sounds);

void diamond_draw(DIAMOND *diamonds, int diamondQuantity, SPRITES *sprites);

#endif