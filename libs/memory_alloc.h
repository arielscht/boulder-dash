#include "boulder.h"
#include "diamond.h"
#include "dirt.h"
#include "steelWall.h"
#include "wall.h"

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