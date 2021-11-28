#ifndef __MAPS__
#define __MAPS__

#include <stdio.h>
#include "../../utils/utils/utils.h"
#include "../../entities/boulder/boulder.h"
#include "../../entities/diamond/diamond.h"
#include "../../entities/steelWall/steelWall.h"
#include "../../entities/wall/wall.h"
#include "../../entities/firefly/firefly.h"
#include "../../entities/dirt/dirt.h"
#include "../../entities/exit/exit.h"
#include "../../utils/constants.h"

void read_map(char map[MAP_HEIGHT][MAP_WIDTH],
              char *mapFile,
              ENTITIES_QUANTITIES *entities,
              MAP_DATA *mapData);

void init_map(char map[MAP_HEIGHT][MAP_WIDTH],
              BOULDER *boulders,
              DIAMOND *diamonds,
              DIRT *dirts,
              STEEL_WALL *steelWalls,
              WALL *walls,
              FIREFLY *fireflies,
              EXIT *exit);

void print_map(char map[MAP_HEIGHT][MAP_WIDTH]);

#endif