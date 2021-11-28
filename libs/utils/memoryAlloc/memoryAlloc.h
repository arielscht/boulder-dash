#ifndef __MEMORYALLOC__
#define __MEMORYALLOC__

#include "../../entities/boulder/boulder.h"
#include "../../entities/diamond/diamond.h"
#include "../../entities/dirt/dirt.h"
#include "../../entities/steelWall/steelWall.h"
#include "../../entities/wall/wall.h"
#include "../../entities/firefly/firefly.h"

void alloc_entities(
    ENTITIES_QUANTITIES *entities,
    BOULDER **boulders,
    DIAMOND **diamonds,
    DIRT **dirts,
    STEEL_WALL **steelWalls,
    WALL **walls,
    FIREFLY **fireflies);

void free_entities(
    BOULDER **boulders,
    DIAMOND **diamonds,
    DIRT **dirts,
    STEEL_WALL **steelWalls,
    WALL **walls,
    FIREFLY **fireflies);

#endif