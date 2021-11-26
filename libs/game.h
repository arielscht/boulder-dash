#ifndef __GAME__
#define __GAME__

#include "constants.h"
#include "rockford.h"
#include "boulder.h"
#include "dirt.h"
#include "diamond.h"
#include "steelWall.h"
#include "wall.h"
#include "exit.h"
#include "utils.h"
#include "maps.h"
#include "memoryAlloc.h"

void start_game(
    char map[MAP_HEIGHT][MAP_WIDTH],
    int *diamondsToWin,
    int *levelScore,
    int *scorePerDiamond,
    ENTITIES_QUANTITIES *entitiesQuantities,
    char *mapFile,
    ROCKFORD *player,
    BOULDER **boulders,
    DIRT **dirts,
    DIAMOND **diamonds,
    STEEL_WALL **steelWalls,
    WALL **walls,
    EXIT *rockfordEntrance,
    EXIT *levelExit);

#endif