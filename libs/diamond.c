#include "diamond.h"

void diamond_update(DIAMOND *diamonds, int diamondQuantity)
{
    for (int i = 0; i < diamondQuantity; i++)
    {
        if (!diamonds[i].shown)
            continue;

        diamonds[i].delay++;

        if (diamonds[i].delay % 5 != 0)
            continue;

        diamonds[i].sourceX += SPRITE_WIDTH;

        if (diamonds[i].sourceX >= SPRITE_WIDTH * 8)
            diamonds[i].sourceX = 0;
    }
}

void diamond_draw(DIAMOND *diamonds, int diamondQuantity, SPRITES *sprites)
{
    for (int i = 0; i < diamondQuantity; i++)
    {
        if (!diamonds[i].shown)
            continue;

        al_draw_bitmap_region(
            sprites->diamond,
            diamonds[i].sourceX,
            diamonds[i].sourceY,
            SPRITE_WIDTH,
            SPRITE_HEIGHT,
            diamonds[i].x,
            diamonds[i].y,
            0);
    }
}