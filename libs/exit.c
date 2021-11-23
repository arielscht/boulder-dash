#include "exit.h"

void exit_update(EXIT *exit, ROCKFORD *player, bool *restart, int *currentMap)
{
    if (!exit->shown)
        return;

    exit->delay++;

    if (exit->delay % 30 != 0)
        return;

    exit->sourceX += SPRITE_WIDTH;

    if (exit->sourceX == SPRITE_WIDTH * 2)
        exit->sourceX = 0;

    if (exit->x == player->x && exit->y == player->y)
    {
        *restart = true;
        *currentMap = *currentMap + 1;
    }
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

void rockford_entrance_init(ROCKFORD *player, EXIT *entrance)
{
    entrance->x = player->x;
    entrance->y = player->y;
    entrance->shown = true;
    entrance->delay = 0;
    entrance->sourceX = 0;
}

void rockford_entrance_update(EXIT *entrance, ROCKFORD *player)
{
    if (!entrance->shown)
        return;

    entrance->delay++;

    if (entrance->delay % 20 != 0)
        return;

    entrance->sourceX += SPRITE_WIDTH;

    if (entrance->sourceX == SPRITE_WIDTH * 2)
        entrance->sourceX = 0;

    if (entrance->delay % 180 == 0)
    {
        entrance->shown = false;
        player->entering = false;
    }
}