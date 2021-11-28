#include "firefly.h"

void firefly_update(FIREFLY *fireflies, int fireflyQtd, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < fireflyQtd; i++)
    {
        if (!fireflies[i].shown)
            continue;

        fireflies[i].delay++;

        if (fireflies[i].delay % 5 != 0)
            continue;

        fireflies[i].sourceX += SPRITE_WIDTH;

        if (fireflies[i].sourceX >= SPRITE_WIDTH * 8)
            fireflies[i].sourceX = 0;
    }
}

void firefly_draw(FIREFLY *fireflies, int fireflyQtd, SPRITES *sprites)
{
    for (int i = 0; i < fireflyQtd; i++)
    {
        if (!fireflies[i].shown)
            continue;

        al_draw_bitmap_region(sprites->firefly,
                              fireflies[i].sourceX,
                              fireflies[i].sourceY,
                              SPRITE_WIDTH,
                              SPRITE_HEIGHT,
                              fireflies[i].x,
                              fireflies[i].y,
                              0);
    }
}