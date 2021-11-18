#include "boulder.h"

void boulder_falling(BOULDER *boulder, char map[MAP_HEIGHT][MAP_WIDTH])
{
    int x = get_map_x_position(boulder->x);
    int y = get_map_y_position(boulder->y);

    if (map[y + 1][x] == MAP_BLANK)
    {
        if (!boulder->falling)
        {
            boulder->falling = true;
            return;
        }
        map[y][x] = MAP_BLANK;
        map[y + 1][x] = MAP_BOULDER;
        boulder->y += SPRITE_WIDTH;
    }
    else if (map[y + 1][x] == MAP_BOULDER || map[y + 1][x] == MAP_DIAMOND || map[y + 1][x] == MAP_WALL)
    {
        if (map[y][x - 1] == MAP_BLANK &&
            map[y + 1][x - 1] == MAP_BLANK)
        {
            if (!boulder->falling)
            {
                boulder->falling = true;
                return;
            }
            map[y][x] = MAP_BLANK;
            map[y][x - 1] = MAP_BOULDER;
            boulder->x -= SPRITE_WIDTH;
        }
        else if (map[y][x + 1] == MAP_BLANK && map[y + 1][x + 1] == MAP_BLANK)
        {
            if (!boulder->falling)
            {
                boulder->falling = true;
                return;
            }
            map[y][x] = MAP_BLANK;
            map[y][x + 1] = MAP_BOULDER;
            boulder->x += SPRITE_WIDTH;
        }
        else
        {
            boulder->falling = false;
        }
    }
    else
    {
        boulder->falling = false;
    }
}

void boulder_update(BOULDER *boulders, int boulderQuantity, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < boulderQuantity; i++)
    {
        boulders[i].delay++;

        if (boulders[i].delay % 5 != 0)
            continue;

        boulder_falling(&boulders[i], map);
    }
}

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites)
{
    for (int i = 0; i < boulderQuantity; i++)
        al_draw_bitmap(
            sprites->boulder,
            boulders[i].x,
            boulders[i].y,
            0);
}
