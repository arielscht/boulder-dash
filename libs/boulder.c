#include "boulder.h"

void boulder_update(BOULDER *boulders, int boulderQuantity, char map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < boulderQuantity; i++)
    {
        boulders[i].delay++;

        if (boulders[i].delay % 5 != 0)
            continue;

        int boulderX = get_map_x_position(boulders[i].x);
        int boulderY = get_map_y_position(boulders[i].y);

        if (map[boulderY + 1][boulderX] == MAP_BLANK)
        {
            map[boulderY][boulderX] = MAP_BLANK;
            map[boulderY + 1][boulderX] = MAP_BOULDER;
            boulders[i].y += SPRITE_WIDTH;
        }
        else if (map[boulderY + 1][boulderX] == MAP_BOULDER || map[boulderY + 1][boulderX] == MAP_DIAMOND)
        {
            if (map[boulderY][boulderX - 1] == MAP_BLANK &&
                map[boulderY + 1][boulderX - 1] == MAP_BLANK)
            {
                map[boulderY][boulderX] = MAP_BLANK;
                map[boulderY][boulderX - 1] = MAP_BOULDER;
                boulders[i].x -= SPRITE_WIDTH;
            }
            else if (map[boulderY][boulderX + 1] == MAP_BLANK && map[boulderY + 1][boulderX + 1] == MAP_BLANK)
            {
                map[boulderY][boulderX] = MAP_BLANK;
                map[boulderY][boulderX + 1] = MAP_BOULDER;
                boulders[i].x += SPRITE_WIDTH;
            }
        }
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
