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
    }
}

void explosion_update(EXPLOSION *explosions)
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