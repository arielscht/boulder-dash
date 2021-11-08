#include <allegro5/allegro.h>

#ifndef __UTILS__
#define __UTILS__
typedef enum DIRECTIONS
{
    UP_DIR,
    DOWN_DIR,
    LEFT_DIR,
    RIGHT_DIR,
} DIRECTIONS;

#endif

void must_init(bool test, const char *description);