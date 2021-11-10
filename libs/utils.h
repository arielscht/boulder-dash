#include <allegro5/allegro.h>
#include "boulder.h"
#include "diamond.h"
#include "dirt.h"
#include "wall.h"
#include "steelWall.h"

#ifndef __UTILS__
#define __UTILS__
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

#endif

void must_init(bool test, const char *description);

void must_alloc(bool test, const char *description);

void init_entities_count(ENTITIES_QUANTITIES *entities);

void alloc_entities(
    ENTITIES_QUANTITIES *entities,
    BOULDER **boulders,
    DIAMOND **diamonds,
    DIRT **dirts,
    STEEL_WALL **steelWalls,
    WALL **walls);

void free_entities(ENTITIES_QUANTITIES *entities,
                   BOULDER *boulders,
                   DIAMOND *diamonds,
                   DIRT *dirts,
                   STEEL_WALL *steelWalls,
                   WALL *walls);