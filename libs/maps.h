#ifndef __MAPS__
#define __MAPS__

#include <stdio.h>
#include "utils.h"
#include "boulder.h"
#include "diamond.h"
#include "steelWall.h"
#include "wall.h"
#include "dirt.h"
#include "constants.h"
#include "exit.h"

void read_map(char map[MAP_HEIGHT][MAP_WIDTH],
              char *mapFile,
              ENTITIES_QUANTITIES *entities,
              int *diamondsToWin);

void init_map(char map[MAP_HEIGHT][MAP_WIDTH],
              BOULDER *boulders,
              DIAMOND *diamonds,
              DIRT *dirts,
              STEEL_WALL *steelWalls,
              WALL *walls,
              EXIT *exit);

void print_map(char map[MAP_HEIGHT][MAP_WIDTH]);

#endif