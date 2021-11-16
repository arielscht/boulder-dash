#include "dirt.h"
#include "utils.h"
#include "constants.h"

void dirt_update(DIRT *dirts, int dirtQuantity, ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < dirtQuantity; i++)
    {
        if (!dirts[i].shown)
            continue;

        if (player->x == dirts[i].x && player->y == dirts[i].y)
        {
            map[get_map_y_position(dirts[i].y)][get_map_x_position(dirts[i].x)] = 'O';
            dirts[i].shown = false;
            for (int i = 0; i < MAP_HEIGHT; i++)
            {
                for (int j = 0; j < MAP_WIDTH; j++)
                {
                    printf("%c ", map[i][j]);
                }
                printf("\n");
            }
        }
    }
}

void dirt_draw(DIRT *dirts, int dirtQuantity, SPRITES *sprites)
{
    for (int i = 0; i < dirtQuantity; i++)
    {
        if (!dirts[i].shown)
            continue;

        al_draw_bitmap(
            sprites->dirt,
            dirts[i].x,
            dirts[i].y,
            0);
    }
}