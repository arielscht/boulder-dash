#ifndef __EXPLOSIONS__
#define __EXPLOSIONS__

#include <allegro5/allegro.h>
#include "sprites.h"
#include "utils.h"

#define MAX_EXPLOSIONS 100

typedef struct EXPLOSION
{
    int x, y;
    int sourceX;
    int sprite_dir;
    int delay;
    bool used;
} EXPLOSION;

void explosion_init(EXPLOSION *explosions);
void explosion_add(int x, int y, EXPLOSION *explosions);
void explosion_update(EXPLOSION *explosions, char map[MAP_HEIGHT][MAP_WIDTH]);
void explosion_draw(EXPLOSION *explosions, SPRITES *sprites);
void explode_map_area(EXPLOSION *explosions,
                      int centerX,
                      int centerY,
                      char map[MAP_HEIGHT][MAP_WIDTH]);

#endif