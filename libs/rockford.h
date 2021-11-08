#include <allegro5/allegro.h>
#include "sprites.h"
#include "utils.h"
typedef struct ROCKFORD
{
    int x, y;
    int sourceX, sourceY;
    int frame;
    int delay;
    DIRECTIONS direction;
    DIRECTIONS last_direction;
    bool active;
} ROCKFORD;

void rockford_init(ROCKFORD *player);
void rockford_update(ROCKFORD *player, unsigned char *keyboard);
void rockford_draw(ROCKFORD *player, SPRITES *sprites);