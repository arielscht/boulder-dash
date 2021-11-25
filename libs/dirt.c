#include "dirt.h"
#include "utils.h"
#include "constants.h"

void dirt_update(DIRT *dirts,
                 int dirtQuantity,
                 ROCKFORD *player,
                 char map[MAP_HEIGHT][MAP_WIDTH],
                 SOUNDS *sounds)
{
    for (int i = 0; i < dirtQuantity; i++)
    {
        if (!dirts[i].shown)
            continue;

        int dirtX = get_map_x_position(dirts[i].x);
        int dirtY = get_map_y_position(dirts[i].y);

        if (map[dirtY][dirtX] == MAP_BLANK)
        {
            dirts[i].shown = false;
            return;
        }

        if (player->x == dirts[i].x && player->y == dirts[i].y)
        {
            al_play_sample(sounds->dirt, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            dirts[i].shown = false;
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