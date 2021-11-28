#ifndef __CONSTANTS__
#define __CONSTANTS__

#include "./display/display.h"
#include "../loadables/sprites/sprites.h"

#define MAP_WIDTH 40
#define MAP_HEIGHT 22
#define MAP_QUANTITY 3

#define SPRITE_MAX_X (BUFFER_WIDTH - SPRITE_WIDTH * 2)
#define SPRITE_MAX_Y (BUFFER_HEIGHT - SPRITE_HEIGHT * 2)

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

#define MAX_SCORE_STORED 5

#endif