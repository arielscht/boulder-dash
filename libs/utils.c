#include "utils.h"
#include "sprites.h"

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void must_alloc(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't allocate memory for the %s\n", description);
    exit(1);
}

void init_entities_count(ENTITIES_QUANTITIES *entities)
{
    entities->boulder = 0;
    entities->diamond = 0;
    entities->dirt = 0;
    entities->steelWall = 0;
    entities->wall = 0;
}

int get_map_x_position(int x)
{
    return x / SPRITE_WIDTH;
}

int get_map_y_position(int y)
{
    return (y / SPRITE_HEIGHT) - 1;
}