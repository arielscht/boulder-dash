#include <allegro5/allegro.h>
#include "rockford.h"
#include "sprites.h"
#include "display.h"
#include "constants.h"
#include "utils.h"

void rockford_init(ROCKFORD *player)
{
    player->x = 0;
    player->y = 0;
    player->frame = 0;
    player->sourceX = 0;
    player->sourceY = 0;
    player->delay = 0;
    player->active = false;
    player->direction = UP_DIR;
    player->last_direction = UP_DIR;
}

void rockford_update(ROCKFORD *player, unsigned char *keyboard)
{
    player->delay++;

    if (player->delay % 5 != 0)
        return;

    player->active = true;
    if (keyboard[ALLEGRO_KEY_LEFT])
    {
        player->x -= SPRITE_WIDTH;
        player->last_direction = player->direction;
        player->direction = LEFT_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_RIGHT])
    {
        player->x += SPRITE_WIDTH;
        player->last_direction = player->direction;
        player->direction = RIGHT_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_UP])
    {
        player->y -= SPRITE_HEIGHT;
        player->last_direction = player->direction;
        player->direction = UP_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_DOWN])
    {
        player->y += SPRITE_HEIGHT;
        player->last_direction = player->direction;
        player->direction = DOWN_DIR;
    }
    else
    {
        player->active = false;
    }

    if (player->last_direction != player->direction)
    {
        player->sourceX = 0;
        player->sourceY = 0;
    }

    if (player->x < SPRITE_WIDTH)
        player->x = SPRITE_WIDTH;
    if (player->y < SPRITE_HEIGHT)
        player->y = SPRITE_HEIGHT;

    if (player->x >= SPRITE_MAX_X)
        player->x = SPRITE_MAX_X;
    if (player->y >= SPRITE_MAX_Y)
        player->y = SPRITE_MAX_Y;
}

void rockford_draw(ROCKFORD *player, SPRITES *sprites)
{
    if (player->active)
    {
        if (player->direction == RIGHT_DIR || (player->last_direction == RIGHT_DIR && (player->direction == UP_DIR || player->direction == DOWN_DIR)))
        {
            if (player->last_direction != RIGHT_DIR)
                player->frame = 0;

            al_draw_bitmap_region(
                sprites->rockford[ROCKFORD_MOVING_RIGHT],
                player->sourceX, player->sourceY, SPRITE_WIDTH, SPRITE_HEIGHT,
                player->x, player->y, 0);

            if (player->frame % 3 == 0)
                player->sourceX += SPRITE_WIDTH;

            player->frame++;

            if (player->sourceX >= SPRITE_WIDTH * 8)
                player->sourceX = 0;
        }
        else if (player->direction == LEFT_DIR || (player->last_direction == LEFT_DIR && (player->direction == UP_DIR || player->direction == DOWN_DIR)))
        {
            if (player->last_direction != LEFT_DIR)
                player->frame = 0;

            al_draw_bitmap_region(
                sprites->rockford[ROCKFORD_MOVING_LEFT],
                player->sourceX, player->sourceY, SPRITE_WIDTH, SPRITE_HEIGHT,
                player->x, player->y, 0);

            if (player->frame % 3 == 0)
                player->sourceX += SPRITE_WIDTH;

            player->frame++;

            if (player->sourceX >= SPRITE_WIDTH * 8)
                player->sourceX = 0;
        }
        else
        {
            al_draw_bitmap_region(
                sprites->rockford[ROCKFORD_STAND_STILL],
                0, 0, SPRITE_WIDTH, SPRITE_HEIGHT,
                player->x, player->y, 0);
        }

        // player->last_direction = player->direction;
    }
    else
    {
        // if (player->last_direction != LEFT_DIR)
        //     player->frame = 0;

        al_draw_bitmap_region(
            sprites->rockford[ROCKFORD_ANIMATED],
            player->sourceX, player->sourceY, SPRITE_WIDTH, SPRITE_HEIGHT,
            player->x, player->y, 0);

        if (player->frame % 3 == 0)
            player->sourceX += SPRITE_WIDTH;

        if (player->frame % 72 == 0)
            player->sourceY += SPRITE_HEIGHT;

        player->frame++;

        if (player->sourceX >= SPRITE_WIDTH * 8)
            player->sourceX = 0;

        if (player->sourceY >= SPRITE_HEIGHT * 3)
            player->sourceY = 0;
    }
}