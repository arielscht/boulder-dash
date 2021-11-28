#ifndef __EXIT__
#define __EXIT__

#include "../../loadables/sprites/sprites.h"
#include "../../utils/constants.h"
#include "../rockford/rockford.h"
#include "../../loadables/audio/audio.h"
#include "../../general/score/score.h"
#include "../../utils/utils/utils.h"

typedef struct EXIT
{
    int x;
    int y;
    int delay;
    int sourceX;
    bool shown;
} EXIT;

void thunder_update(ROCKFORD *player, MAP_DATA *mapData, EXIT *exit, SOUNDS *sounds);

void exit_update(EXIT *exit, ROCKFORD *player, GAME_FLAGS *gameFlags, MAP_DATA *mapData);

void exit_draw(EXIT *exit, SPRITES *sprites, bool isExit);

void rockford_entrance_init(ROCKFORD *player, EXIT *exit);

void rockford_entrance_update(EXIT *entrance, ROCKFORD *player, SOUNDS *sounds);

#endif