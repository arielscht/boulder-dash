#include "explosion.h"

void explosion_init(EXPLOSION *explosions)
{
    for (int i = 0; i < MAX_EXPLOSIONS; i++)
        explosions[i].used = false;
}

void explosion_add(int x, int y, EXPLOSION *explosions)
{
    for (int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if (explosions[i].used)
            continue;

        explosions[i].used = true;
        explosions[i].x = x;
        explosions[i].y = y;
        explosions[i].sourceX = 0;
        explosions[i].delay = 0;
        explosions[i].sprite_dir = 1;
        return;
    }
}

void explosion_update(EXPLOSION *explosions, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if (!explosions[i].used)
            continue;

        explosions[i].delay++;

        if (explosions[i].delay % 5 != 0)
            continue;

        if (explosions[i].sprite_dir == 1)
            explosions[i].sourceX += SPRITE_WIDTH;
        else
            explosions[i].sourceX -= SPRITE_WIDTH;

        if (explosions[i].sourceX >= SPRITE_WIDTH * 2)
            explosions[i].sprite_dir = -1;
        else if (explosions[i].sourceX == 0)
            explosions[i].sprite_dir = 1;

        if (explosions[i].delay % 25 == 0)
        {
            int mapX = get_map_x_position(explosions[i].x);
            int mapY = get_map_y_position(explosions[i].y);
            map[mapY][mapX] = MAP_BLANK;
            explosions[i].used = false;
        }
    }
}

void explosion_draw(EXPLOSION *explosions, SPRITES *sprites)
{
    for (int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if (!explosions[i].used)
            continue;

        al_draw_bitmap_region(
            sprites->explosion,
            explosions->sourceX,
            0,
            SPRITE_WIDTH,
            SPRITE_HEIGHT,
            explosions[i].x,
            explosions[i].y,
            0);
    }
};

void explode_map_area(EXPLOSION *explosions,
                      int centerX,
                      int centerY,
                      char map[MAP_HEIGHT][MAP_WIDTH])
{
    int initX = centerX - SPRITE_WIDTH;
    int initY = centerY - SPRITE_WIDTH;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int explosionX = initX + (SPRITE_WIDTH * j);
            int explosionY = initY + (SPRITE_HEIGHT * i);

            int mapX = get_map_x_position(explosionX);
            int mapY = get_map_y_position(explosionY);

            //Check because steel walls do not explode
            if (map[mapY][mapX] != MAP_STEEL_WALL)
            {
                explosion_add(
                    explosionX,
                    explosionY,
                    explosions);
            }
        }
    }
}