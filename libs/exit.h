#ifndef __EXIT__
#define __EXIT__

#include "sprites.h"
#include "constants.h"
#include "rockford.h"
#include "audio.h"

typedef struct EXIT
{
    int x;
    int y;
    int delay;
    int sourceX;
    bool shown;
} EXIT;

void exit_update(EXIT *exit, ROCKFORD *player, bool *restart, int *currentMap, MAP_DATA *mapData);

void exit_draw(EXIT *exit, SPRITES *sprites, bool isExit);

void rockford_entrance_init(ROCKFORD *player, EXIT *exit);

void rockford_entrance_update(EXIT *entrance, ROCKFORD *player, SOUNDS *sounds);

#endif