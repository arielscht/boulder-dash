#include <allegro5/allegro.h>
#include "sprites.h"
#include "../../utils/utils/utils.h"

ALLEGRO_BITMAP *sprite_grab(int x, int y, int w, int h, ALLEGRO_BITMAP *spritesheet)
{
    ALLEGRO_BITMAP *sprite = al_create_sub_bitmap(spritesheet, x, y, w, h);
    must_init(sprite, "sprite grab");
    return sprite;
}

void sprites_init(SPRITES *sprites)
{
    sprites->spritesheet = al_load_bitmap("./resources/sprites.png");

    //LOAD ROCKFORD;
    sprites->rockford[ROCKFORD_STAND_STILL] = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 0, SPRITE_WIDTH, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->rockford[ROCKFORD_ANIMATED] = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 1, SPRITE_WIDTH * 8, SPRITE_HEIGHT * 3, sprites->spritesheet);
    sprites->rockford[ROCKFORD_MOVING_LEFT] = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 4, SPRITE_WIDTH * 8, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->rockford[ROCKFORD_MOVING_RIGHT] = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 5, SPRITE_WIDTH * 8, SPRITE_HEIGHT, sprites->spritesheet);

    sprites->dirt = sprite_grab(SPRITE_WIDTH * 1, SPRITE_HEIGHT * 7, SPRITE_WIDTH, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->boulder = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 7, SPRITE_WIDTH, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->wall = sprite_grab(SPRITE_WIDTH * 3, SPRITE_HEIGHT * 6, SPRITE_WIDTH, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->steel_wall = sprite_grab(SPRITE_WIDTH * 1, SPRITE_HEIGHT * 6, SPRITE_WIDTH, SPRITE_HEIGHT, sprites->spritesheet);

    sprites->magic_wall = sprite_grab(SPRITE_WIDTH * 4, SPRITE_HEIGHT * 6, SPRITE_WIDTH * 4, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->firefly = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 9, SPRITE_WIDTH * 8, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->butterfly = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 11, SPRITE_WIDTH * 8, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->amoeba = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 8, SPRITE_WIDTH * 8, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->diamond = sprite_grab(SPRITE_WIDTH * 0, SPRITE_HEIGHT * 10, SPRITE_WIDTH * 8, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->exit = sprite_grab(SPRITE_WIDTH * 1, SPRITE_HEIGHT * 6, SPRITE_WIDTH * 2, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->explosion = sprite_grab(SPRITE_WIDTH * 3, SPRITE_HEIGHT * 7, SPRITE_WIDTH * 3, SPRITE_HEIGHT, sprites->spritesheet);
    sprites->diamondIcon = sprite_grab(SPRITE_WIDTH * 8, SPRITE_HEIGHT * 2, SPRITE_WIDTH, SPRITE_HEIGHT / 2, sprites->spritesheet);
}

void sprites_deinit(SPRITES *sprites)
{
    al_destroy_bitmap(sprites->spritesheet);

    for (int i = 0; i < ROCKFORD_ANIMATION_N; i++)
        al_destroy_bitmap(sprites->rockford[i]);

    al_destroy_bitmap(sprites->dirt);
    al_destroy_bitmap(sprites->boulder);
    al_destroy_bitmap(sprites->wall);
    al_destroy_bitmap(sprites->steel_wall);

    al_destroy_bitmap(sprites->magic_wall);
    al_destroy_bitmap(sprites->firefly);
    al_destroy_bitmap(sprites->butterfly);
    al_destroy_bitmap(sprites->amoeba);
    al_destroy_bitmap(sprites->diamond);
    al_destroy_bitmap(sprites->exit);
    al_destroy_bitmap(sprites->explosion);
    al_destroy_bitmap(sprites->diamondIcon);
}
