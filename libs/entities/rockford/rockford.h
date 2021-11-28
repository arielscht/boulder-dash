#ifndef __ROCKFORD__
#define __ROCKFORD__

#include <allegro5/allegro.h>
#include "../../loadables/sprites/sprites.h"
#include "../../utils/utils/utils.h"
#include "../../utils/display/display.h"
#include "../../utils/constants.h"
#include "../explosion/explosion.h"
#include "../../loadables/audio/audio.h"
#include "../../general/score/score.h"

typedef struct ROCKFORD
{
    int x, y;
    int sourceX, sourceY;
    int delay;
    int previousScore, score;
    int lives;
    int diamondsObtained;
    DIRECTIONS direction;
    DIRECTIONS last_direction;
    bool entering;
    bool alive;
    bool locked;
    bool exploded;
    bool active;
} ROCKFORD;

void rockford_init_map(ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH], bool restartScore);
void rockford_init_score(ROCKFORD *player);
void rockford_update(ROCKFORD *player,
                     unsigned char *keyboard,
                     char map[MAP_HEIGHT][MAP_WIDTH],
                     EXPLOSION *explosions,
                     GAME_FLAGS *gameFlags,
                     SOUNDS *sounds,
                     bool exitOpen,
                     MAP_DATA *mapData);
void rockford_draw(ROCKFORD *player, SPRITES *sprites);

#endif