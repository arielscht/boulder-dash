#include "utils.h"
#include "../../loadables/sprites/sprites.h"

//util function to check if some pointer was initialized
void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

//check if memory was allocated
void must_alloc(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't allocate memory for the %s\n", description);
    exit(1);
}

//initialize the entities counters
void init_entities_count(ENTITIES_QUANTITIES *entities)
{
    entities->boulder = 0;
    entities->diamond = 0;
    entities->dirt = 0;
    entities->steelWall = 0;
    entities->wall = 0;
}

//initialize the game flags
void init_game_flags(GAME_FLAGS *gameFlags)
{
    gameFlags->cheatActivated = false;
    gameFlags->done = false;
    gameFlags->helpOpen = false;
    gameFlags->scoreOpen = false;
    gameFlags->restart = true;
    gameFlags->redraw = true;
}

//get the map x position in the matrix when given a pixel location in the screen
int get_map_x_position(int x)
{
    return x / SPRITE_WIDTH;
}

//get the map y position in the matrix when given a pixel location in the screen
int get_map_y_position(int y)
{
    return (y / SPRITE_HEIGHT) - 1;
}