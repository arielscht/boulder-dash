#include "boulder.h"

void boulder_falling(BOULDER *boulder,
                     int x, int y,
                     ROCKFORD *player,
                     char map[MAP_HEIGHT][MAP_WIDTH],
                     SOUNDS *sounds)
{

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
        else if (boulder->falling)
        {
            al_play_sample(sounds->boulderFall, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            boulder->falling = false;
        }
    }
    else if (boulder->falling && map[y + 1][x] == MAP_ROCKFORD && player->alive)
    {
        player->alive = false;
        player->lives = player->lives - 1;
    }
    else if (boulder->falling)
    {
        al_play_sample(sounds->boulderFall, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        boulder->falling = false;
    }
}

void boulder_pushed(BOULDER *boulder, int x, int y, ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH])
{
    if (player->active &&
        player->x == boulder->x - SPRITE_WIDTH &&
        player->y == boulder->y &&
        player->direction == RIGHT_DIR &&
        map[get_map_y_position(boulder->y)][get_map_x_position(boulder->x) + 1] == MAP_BLANK)
    {
        boulder->pushed++;
        if (boulder->pushed % 10 == 0)
        {
            boulder->x += SPRITE_WIDTH;
            player->x += SPRITE_WIDTH;
            map[y][x - 1] = MAP_BLANK;
            map[y][x] = MAP_ROCKFORD;
            map[y][x + 1] = MAP_BOULDER;
        }
    }
    else if (player->active &&
             player->x == boulder->x + SPRITE_WIDTH &&
             player->y == boulder->y &&
             player->direction == LEFT_DIR &&
             map[get_map_y_position(boulder->y)][get_map_x_position(boulder->x) - 1] == MAP_BLANK)
    {
        boulder->pushed++;
        if (boulder->pushed % 10 == 0)
        {
            boulder->x -= SPRITE_WIDTH;
            player->x -= SPRITE_WIDTH;
            map[y][x + 1] = MAP_BLANK;
            map[y][x] = MAP_ROCKFORD;
            map[y][x - 1] = MAP_BOULDER;
        }
    }
    else
    {
        boulder->pushed = 0;
    }
}

void boulder_update(
    BOULDER *boulders,
    int boulderQuantity,
    ROCKFORD *player,
    char map[MAP_HEIGHT][MAP_WIDTH],
    SOUNDS *sounds)
{
    for (int i = 0; i < boulderQuantity; i++)
    {
        if (!boulders[i].shown)
            continue;

        boulders[i].delay++;

        if (boulders[i].delay % 5 != 0)
            continue;

        int boulderX = get_map_x_position(boulders[i].x);
        int boulderY = get_map_y_position(boulders[i].y);

        if (map[boulderY][boulderX] == MAP_BLANK)
        {
            boulders[i].shown = false;
            return;
        }

        boulder_pushed(&boulders[i], boulderX, boulderY, player, map);
        boulder_falling(&boulders[i], boulderX, boulderY, player, map, sounds);
    }
}

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites)
{
    for (int i = 0; i < boulderQuantity; i++)
    {
        if (!boulders[i].shown)
            continue;

        al_draw_bitmap(
            sprites->boulder,
            boulders[i].x,
            boulders[i].y,
            0);
    }
}
