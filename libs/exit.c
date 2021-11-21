#include "exit.h"

void exit_update(EXIT *exit)
{
    if (!exit->shown)
        return;

    exit->delay++;

    if (exit->delay % 30 != 0)
        return;

    exit->sourceX += SPRITE_WIDTH;

    if (exit->sourceX == SPRITE_WIDTH * 2)
        exit->sourceX = 0;
}

void exit_draw(EXIT *exit, SPRITES *sprites, bool isExit)
{
    if (!exit->shown && !isExit)
        return;

    al_draw_bitmap_region(sprites->exit,
                          exit->sourceX,
                          0,
                          SPRITE_WIDTH,
                          SPRITE_HEIGHT,
                          exit->x,
                          exit->y, 0);
}