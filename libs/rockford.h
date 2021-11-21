#ifndef __ROCKFORD__
#define __ROCKFORD__

#include <allegro5/allegro.h>
#include "sprites.h"
#include "utils.h"
#include "display.h"
#include "constants.h"
#include "explosion.h"
#include "exit.h"

typedef struct ROCKFORD
{
    int x, y;
    int sourceX, sourceY;
    int delay;
    int score;
    DIRECTIONS direction;
    DIRECTIONS last_direction;
    bool entering;
    bool alive;
    bool exploded;
    bool active;
} ROCKFORD;

void rockford_init(ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH]);
void rockford_update(ROCKFORD *player, unsigned char *keyboard, char map[MAP_HEIGHT][MAP_WIDTH], EXPLOSION *explosions);
void rockford_draw(ROCKFORD *player, SPRITES *sprites);
void rockford_entrance_init(ROCKFORD *player, EXIT *exit);
void rockford_entrance_update(EXIT *entrance, ROCKFORD *player);

#endif