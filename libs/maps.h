#ifndef __MAPS__
#define __MAPS__

#include <stdio.h>
#include "utils.h"
#include "boulder.h"
#include "diamond.h"
#include "steelWall.h"
#include "wall.h"
#include "dirt.h"

#define MAP_ROCKFORD 'R'
#define MAP_DIRT 'I'
#define MAP_BOULDER 'B'
#define MAP_DIAMOND 'D'
#define MAP_WALL 'W'
#define MAP_STEEL_WALL 'S'
#define MAP_MAGIC_WALL 'M'
#define MAP_FIREFLY 'F'
#define MAP_BUTTERFLY 'Y'
#define MAP_AMOEBA 'A'
#define MAP_EXIT 'E'
#define MAP_BLANK 'O'

#define MAP_WIDTH 40
#define MAP_HEIGHT 22

void read_map(char map[MAP_HEIGHT][MAP_WIDTH], char *mapFile, ENTITIES_QUANTITIES *entities);

void init_map(char map[MAP_HEIGHT][MAP_WIDTH],
              BOULDER *boulders,
              DIAMOND *diamonds,
              DIRT *dirts,
              STEEL_WALL *steelWalls,
              WALL *walls);

#endif