#include "sprites.h"
#include "steelWall.h"

void steel_wall_draw(STEEL_WALL *walls, int wallQuantity, SPRITES *sprites)
{
    for (int i = 0; i < wallQuantity; i++)
        al_draw_bitmap(sprites->steel_wall, walls[i].x, walls[i].y, 0);
}