#ifndef __GAME__
#define __GAME__

#include "../../utils/constants.h"
#include "../../entities/rockford/rockford.h"
#include "../../entities/boulder/boulder.h"
#include "../../entities/dirt/dirt.h"
#include "../../entities/diamond/diamond.h"
#include "../../entities/steelWall/steelWall.h"
#include "../../entities/wall/wall.h"
#include "../../entities/firefly/firefly.h"
#include "../../entities/exit/exit.h"
#include "../../utils/utils/utils.h"
#include "../maps/maps.h"
#include "../../utils/memoryAlloc/memoryAlloc.h"

void start_game(
    char map[MAP_HEIGHT][MAP_WIDTH],
    MAP_DATA *mapData,
    ENTITIES_QUANTITIES *entitiesQuantities,
    char *mapFile,
    ROCKFORD *player,
    BOULDER **boulders,
    DIRT **dirts,
    DIAMOND **diamonds,
    STEEL_WALL **steelWalls,
    WALL **walls,
    FIREFLY **fireflies,
    EXIT *rockfordEntrance,
    EXIT *levelExit);

#endif