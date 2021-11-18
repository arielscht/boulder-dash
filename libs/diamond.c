#include "diamond.h"

void diamond_falling(DIAMOND *diamond, char map[MAP_HEIGHT][MAP_WIDTH])
{
    int x = get_map_x_position(diamond->x);
    int y = get_map_y_position(diamond->y);

    if (map[y + 1][x] == MAP_BLANK)
    {
        if (!diamond->falling)
        {
            diamond->falling = true;
            return;
        }
        map[y][x] = MAP_BLANK;
        map[y + 1][x] = MAP_DIAMOND;
        diamond->y += SPRITE_WIDTH;
    }
    else if (map[y + 1][x] == MAP_BOULDER || map[y + 1][x] == MAP_DIAMOND || map[y + 1][x] == MAP_WALL)
    {
        if (map[y][x - 1] == MAP_BLANK &&
            map[y + 1][x - 1] == MAP_BLANK)
        {
            if (!diamond->falling)
            {
                diamond->falling = true;
                return;
            }
            map[y][x] = MAP_BLANK;
            map[y][x - 1] = MAP_DIAMOND;
            diamond->x -= SPRITE_WIDTH;
        }
        else if (map[y][x + 1] == MAP_BLANK && map[y + 1][x + 1] == MAP_BLANK)
        {
            if (!diamond->falling)
            {
                diamond->falling = true;
                return;
            }
            map[y][x] = MAP_BLANK;
            map[y][x + 1] = MAP_DIAMOND;
            diamond->x += SPRITE_WIDTH;
        }
        else
        {
            diamond->falling = false;
        }
    }
    else
    {
        diamond->falling = false;
    }
}

void diamond_update(DIAMOND *diamonds, int diamondQuantity, ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < diamondQuantity; i++)
    {
        if (!diamonds[i].shown)
            continue;

        diamonds[i].delay++;

        if (diamonds[i].delay % 5 != 0)
            continue;

        diamond_falling(&diamonds[i], map);

        if (player->x == diamonds[i].x && player->y == diamonds[i].y)
        {
            diamonds[i].shown = false;
            player->score += DIAMOND_SCORE;
        }

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