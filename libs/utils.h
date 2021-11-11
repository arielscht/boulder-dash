#ifndef __UTILS__
#define __UTILS__

#include <stdio.h>
#include <allegro5/allegro.h>
#include "sprites.h"

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

void must_init(bool test, const char *description);

void must_alloc(bool test, const char *description);

void init_entities_count(ENTITIES_QUANTITIES *entities);

#endif