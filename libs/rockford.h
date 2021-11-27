#ifndef __ROCKFORD__
#define __ROCKFORD__

#include <allegro5/allegro.h>
#include "sprites.h"
#include "utils.h"
#include "display.h"
#include "constants.h"
#include "explosion.h"
#include "audio.h"
#include "score.h"

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
                     bool *restart,
                     bool *scoreOpen,
                     SOUNDS *sounds,
                     bool exitOpen,
                     MAP_DATA *mapData);
void rockford_draw(ROCKFORD *player, SPRITES *sprites);

#endif