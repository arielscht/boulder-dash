#include "sprites.h"
#include "wall.h"

void wall_draw(WALL *walls, int wallsQuantity, SPRITES *sprites)
{
    for (int i = 0; i < wallsQuantity; i++)
    {
        if (!walls[i].shown)
            continue;

        al_draw_bitmap(sprites->wall, walls[i].x, walls[i].y, 0);
    }
}