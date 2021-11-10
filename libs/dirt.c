#include <stdio.h>
#include "dirt.h"
#include "sprites.h"

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