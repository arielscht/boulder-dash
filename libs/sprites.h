
#ifndef __SPRITES__
#define __SPRITES__

#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32

#include <allegro5/allegro.h>

typedef enum ROCKFORD_ANIMATION
{
    ROCKFORD_STAND_STILL = 0,
    ROCKFORD_ANIMATED,
    ROCKFORD_MOVING_LEFT,
    ROCKFORD_MOVING_RIGHT,
    ROCKFORD_ANIMATION_N
} ROCKFORD_ANIMATION;

typedef struct SPRITES
{
    ALLEGRO_BITMAP *spritesheet;

    ALLEGRO_BITMAP *rockford[ROCKFORD_ANIMATION_N];

    ALLEGRO_BITMAP *dirt;
    ALLEGRO_BITMAP *boulder;
    ALLEGRO_BITMAP *wall;
    ALLEGRO_BITMAP *steel_wall;

    ALLEGRO_BITMAP *magic_wall;
    ALLEGRO_BITMAP *firefly;
    ALLEGRO_BITMAP *butterfly;
    ALLEGRO_BITMAP *amoeba;
    ALLEGRO_BITMAP *diamond;
    ALLEGRO_BITMAP *exit;

} SPRITES;

#endif

ALLEGRO_BITMAP *sprite_grab(int x, int y, int w, int h, ALLEGRO_BITMAP *spritesheet);

void sprites_init(SPRITES *sprites);
void sprites_deinit(SPRITES *sprites);