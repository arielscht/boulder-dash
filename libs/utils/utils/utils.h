#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <allegro5/allegro.h>
#include "../../loadables/sprites/sprites.h"
#include "../constants.h"

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
    int blinkedFrame;
} MAP_DATA;

typedef struct GAME_FLAGS
{
    bool done;
    bool redraw;
    bool restart;
    bool helpOpen;
    bool scoreOpen;
    bool cheatActivated;
} GAME_FLAGS;

void must_init(bool test, const char *description);

void must_alloc(bool test, const char *description);

void init_entities_count(ENTITIES_QUANTITIES *entities);

void init_game_flags(GAME_FLAGS *gameFlags);

int get_map_x_position(int x);

int get_map_y_position(int y);

#endif