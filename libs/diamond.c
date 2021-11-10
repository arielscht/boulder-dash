#include "sprites.h"
#include "diamond.h"

void diamond_draw(DIAMOND *diamonds, int diamondQuantity, SPRITES *sprites)
{
    for (int i = 0; i < diamondQuantity; i++)
    {
        if (!diamonds[i].shown)
            continue;

        al_draw_bitmap_region(
            sprites->diamond,
            0,
            0,
            SPRITE_WIDTH,
            SPRITE_HEIGHT,
            diamonds[i].x,
            diamonds[i].y,
            0);
    }
}