#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <allegro5/allegro.h>
#include "sprites.h"
#include "constants.h"

typedef enum DIRECTIONS
{
    UP_DIR,
    DOWN_DIR,
    LEFT_DIR,
    RIGHT_DIR,
} DIRECTIONS;

typedef struct ENTITIES_QUANTITIES
{
    int boulder;
    int dirt;
    int wall;
    int steelWall;
    int diamond;
} ENTITIES_QUANTITIES;

typedef struct MAP_DATA
{
    int diamondsToWin;
    int levelScore;
    int scorePerDiamond;
    int currentMap;
} MAP_DATA;

void must_init(bool test, const char *description);

void must_alloc(bool test, const char *description);

void init_entities_count(ENTITIES_QUANTITIES *entities);

int get_map_x_position(int x);

int get_map_y_position(int y);

#endif