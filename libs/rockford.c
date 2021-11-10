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
    {
        return;
    }

    player->active = true;
    if (keyboard[ALLEGRO_KEY_LEFT] || keyboard[ALLEGRO_KEY_A])
    {
        player->x -= SPRITE_WIDTH;
        if (player->direction != LEFT_DIR)
            player->last_direction = player->direction;
        player->direction = LEFT_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_RIGHT] || keyboard[ALLEGRO_KEY_D])
    {
        player->x += SPRITE_WIDTH;
        if (player->direction != RIGHT_DIR)
            player->last_direction = player->direction;
        player->direction = RIGHT_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_UP] || keyboard[ALLEGRO_KEY_W])
    {
        player->y -= SPRITE_HEIGHT;
        if (player->direction != UP_DIR && player->direction != DOWN_DIR)
            player->last_direction = player->direction;
        player->direction = UP_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_DOWN] || keyboard[ALLEGRO_KEY_S])
    {
        player->y += SPRITE_HEIGHT;
        if (player->direction != DOWN_DIR && player->direction != UP_DIR)
            player->last_direction = player->direction;
        player->direction = DOWN_DIR;
    }
    else
    {
        player->active = false;
    }

    player->sourceX += SPRITE_WIDTH;

    if (player->sourceX >= SPRITE_WIDTH * 8)
    {
        player->sourceX = 0;
        if (!player->active)
            player->sourceY += SPRITE_WIDTH;
    }

    if (player->sourceY >= SPRITE_HEIGHT * 3 || player->active)
        player->sourceY = 0;

    if (player->x < SPRITE_WIDTH)
        player->x = SPRITE_WIDTH;
    if (player->y < SPRITE_HEIGHT * 2)
        player->y = SPRITE_HEIGHT * 2;

    if (player->x >= SPRITE_MAX_X)
        player->x = SPRITE_MAX_X;
    if (player->y >= SPRITE_MAX_Y)
        player->y = SPRITE_MAX_Y;
}

void rockford_draw(ROCKFORD *player, SPRITES *sprites)
{
    if (player->active)
    {
        if (player->direction == RIGHT_DIR || (player->last_direction == RIGHT_DIR && (player->direction == DOWN_DIR || player->direction == UP_DIR)))
        {
            al_draw_bitmap_region(
                sprites->rockford[ROCKFORD_MOVING_RIGHT],
                player->sourceX, player->sourceY, SPRITE_WIDTH, SPRITE_HEIGHT,
                player->x, player->y, 0);
        }
        else if (player->direction == LEFT_DIR || (player->last_direction == LEFT_DIR && (player->direction == UP_DIR || player->direction == DOWN_DIR)))
        {
            al_draw_bitmap_region(
                sprites->rockford[ROCKFORD_MOVING_LEFT],
                player->sourceX, player->sourceY, SPRITE_WIDTH, SPRITE_HEIGHT,
                player->x, player->y, 0);
        }
        else
        {
            al_draw_bitmap_region(
                sprites->rockford[ROCKFORD_STAND_STILL],
                0, 0, SPRITE_WIDTH, SPRITE_HEIGHT,
                player->x, player->y, 0);
        }
    }
    else
    {
        al_draw_bitmap_region(
            sprites->rockford[ROCKFORD_ANIMATED],
            player->sourceX, player->sourceY, SPRITE_WIDTH, SPRITE_HEIGHT,
            player->x, player->y, 0);
    }
}