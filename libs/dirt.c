#include "dirt.h"

void dirt_update(DIRT *dirts, int dirtQuantity, ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < dirtQuantity; i++)
    {
        if (!dirts[i].shown)
            continue;

        if (player->x == dirts[i].x && player->y == dirts[i].y)
        {
            // map[]
            dirts[i].shown = false;
        }
    }
}

void dirt_draw(DIRT *dirts, int dirtQuantity, SPRITES *sprites)
{
    for (int i = 0; i < dirtQuantity; i++)
    {
        if (!dirts[i].shown)
            continue;

        al_draw_bitmap(
            sprites->dirt,
            dirts[i].x,
            dirts[i].y,
            0);
    }
}