#ifndef __MEMORYALLOC__
#define __MEMORYALLOC__

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
    WALL **walls);

void free_entities(
    BOULDER **boulders,
    DIAMOND **diamonds,
    DIRT **dirts,
    STEEL_WALL **steelWalls,
    WALL **walls);

#endif