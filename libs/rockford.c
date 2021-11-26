#include "rockford.h"

void rockford_init_score(ROCKFORD *player)
{
    player->previousScore = 0;
    player->score = 0;
    player->lives = 3;
}

void rockford_init_map(ROCKFORD *player, char map[MAP_HEIGHT][MAP_WIDTH], bool restartScore)
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            if (map[i][j] == MAP_ROCKFORD)
            {
                player->x = (i + 1) * SPRITE_WIDTH;
                player->y = j * SPRITE_HEIGHT;
            }
        }
    }

    if (restartScore)
    {
        rockford_init_score(player);
    }
    player->score = player->previousScore;
    player->sourceX = 0;
    player->sourceY = 0;
    player->delay = 0;
    player->diamondsObtained = 0;
    player->active = false;
    player->entering = true;
    player->alive = true;
    player->exploded = false;
    player->locked = false;
    player->direction = UP_DIR;
    player->last_direction = UP_DIR;
}

void rockford_update_map(int previousX, int previousY, int x, int y, char map[MAP_HEIGHT][MAP_WIDTH])
{
    map[get_map_y_position(previousY)][get_map_x_position(previousX)] = MAP_BLANK;
    map[get_map_y_position(y)][get_map_x_position(x)] = MAP_ROCKFORD;
}

bool is_allowed_to_move(ROCKFORD *player, char mapItem, SOUNDS *sounds, bool exitOpen)
{
    if (mapItem == MAP_DIRT ||
        mapItem == MAP_DIAMOND ||
        mapItem == MAP_FIREFLY ||
        mapItem == MAP_BUTTERFLY ||
        mapItem == MAP_EXIT ||
        mapItem == MAP_BLANK)
    {
        if (mapItem == MAP_BLANK)
            al_play_sample(sounds->move, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        if (mapItem == MAP_EXIT)
        {
            if (!exitOpen)
                return false;
            else
                player->locked = true;
        }
        return true;
    }
    return false;
}

void rockford_update(ROCKFORD *player,
                     unsigned char *keyboard,
                     char map[MAP_HEIGHT][MAP_WIDTH],
                     EXPLOSION *explosions,
                     bool *restart,
                     SOUNDS *sounds,
                     bool exitOpen,
                     int *currentMap)
{
    if (player->locked)
        return;

    if (!player->alive && player->exploded)
    {
        player->delay++;

        if (player->delay % 150 == 0)
        {
            if (player->lives == -1)
                *currentMap = 0;
            *restart = true;
        }

        return;
    }

    if (player->entering)
        return;

    player->delay++;

    if (player->delay % 5 != 0)
    {
        return;
    }

    player->active = true;
    if (keyboard[ALLEGRO_KEY_LEFT] || keyboard[ALLEGRO_KEY_A])
    {
        if (is_allowed_to_move(player, map[get_map_y_position(player->y)][get_map_x_position(player->x) - 1], sounds, exitOpen))
        {
            rockford_update_map(player->x, player->y, player->x - SPRITE_WIDTH, player->y, map);
            player->x -= SPRITE_WIDTH;
        }
        if (player->direction != LEFT_DIR)
            player->last_direction = player->direction;
        player->direction = LEFT_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_RIGHT] || keyboard[ALLEGRO_KEY_D])
    {
        if (is_allowed_to_move(player, map[get_map_y_position(player->y)][get_map_x_position(player->x) + 1], sounds, exitOpen))
        {
            rockford_update_map(player->x, player->y, player->x + SPRITE_WIDTH, player->y, map);
            player->x += SPRITE_WIDTH;
        }
        if (player->direction != RIGHT_DIR)
            player->last_direction = player->direction;
        player->direction = RIGHT_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_UP] || keyboard[ALLEGRO_KEY_W])
    {
        if (is_allowed_to_move(player, map[get_map_y_position(player->y) - 1][get_map_x_position(player->x)], sounds, exitOpen))
        {
            rockford_update_map(player->x, player->y, player->x, player->y - SPRITE_HEIGHT, map);
            player->y -= SPRITE_HEIGHT;
        }
        if (player->direction != UP_DIR && player->direction != DOWN_DIR)
            player->last_direction = player->direction;
        player->direction = UP_DIR;
    }
    else if (keyboard[ALLEGRO_KEY_DOWN] || keyboard[ALLEGRO_KEY_S])
    {
        if (is_allowed_to_move(player, map[get_map_y_position(player->y) + 1][get_map_x_position(player->x)], sounds, exitOpen))
        {
            rockford_update_map(player->x, player->y, player->x, player->y + SPRITE_HEIGHT, map);
            player->y += SPRITE_HEIGHT;
        }
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

    if (!player->alive)
    {
        if (!player->exploded)
        {
            player->exploded = true;
            player->delay = 0;
            al_play_sample(sounds->explosion, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            explode_map_area(explosions, player->x, player->y, map);
        }
        return;
    }
}

void rockford_draw(ROCKFORD *player, SPRITES *sprites)
{
    if (!player->alive)
        return;

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
