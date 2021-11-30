#include "wall.h"

//update walls
void wall_update(WALL *walls, int wallsQuantity, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < wallsQuantity; i++)
    {
        if (!walls[i].shown)
            return;

        int wallX = get_map_x_position(walls[i].x);
        int wallY = get_map_y_position(walls[i].y);

        //set wall shown to false when it has exploded
        if (map[wallY][wallX] == MAP_BLANK)
            walls[i].shown = false;
    }
}

//draw the walls
void wall_draw(WALL *walls, int wallsQuantity, SPRITES *sprites)
{
    for (int i = 0; i < wallsQuantity; i++)
    {
        if (!walls[i].shown)
            continue;

        al_draw_bitmap(sprites->wall, walls[i].x, walls[i].y, 0);
    }
}