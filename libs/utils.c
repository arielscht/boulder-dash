#include <stdio.h>
#include <allegro5/allegro.h>
#include "utils.h"
#include "boulder.h"
#include "diamond.h"
#include "dirt.h"
#include "wall.h"
#include "steelWall.h"

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void must_alloc(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't allocate memory for the %s\n", description);
    exit(1);
}

void init_entities_count(ENTITIES_QUANTITIES *entities)
{
    entities->boulder = 0;
    entities->diamond = 0;
    entities->dirt = 0;
    entities->steelWall = 0;
    entities->wall = 0;
}

void alloc_entities(
    ENTITIES_QUANTITIES *entities,
    BOULDER **boulders,
    DIAMOND **diamonds,
    DIRT **dirts,
    STEEL_WALL **steelWalls,
    WALL **walls)
{
    *boulders = calloc(entities->boulder, sizeof(BOULDER));
    must_alloc(*boulders, "boulders");

    *dirts = calloc(entities->dirt, sizeof(DIRT));
    must_alloc(*dirts, "dirts");

    *diamonds = calloc(entities->diamond, sizeof(DIAMOND));
    must_alloc(*diamonds, "diamonds");

    *steelWalls = calloc(entities->steelWall, sizeof(STEEL_WALL));
    must_alloc(*steelWalls, "steelWalls");

    *walls = calloc(entities->wall, sizeof(WALL));
    must_alloc(*walls, "walls");
}

void free_entities(ENTITIES_QUANTITIES *entities,
                   BOULDER *boulders,
                   DIAMOND *diamonds,
                   DIRT *dirts,
                   STEEL_WALL *steelWalls,
                   WALL *walls)
{
    // for(int i = 0; i < entities.boulder)
    free(boulders);
    free(diamonds);
    free(dirts);
    free(steelWalls);
    free(walls);
}
