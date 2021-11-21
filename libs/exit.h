#ifndef __EXIT__
#define __EXIT__

#include "sprites.h"
#include "constants.h"

typedef struct EXIT
{
    int x;
    int y;
    int delay;
    int sourceX;
    bool shown;
} EXIT;

void exit_update(EXIT *exit);

void exit_draw(EXIT *exit, SPRITES *sprites, bool isExit);

#endif