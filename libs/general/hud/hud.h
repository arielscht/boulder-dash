#ifndef __HUD__
#define __HUD__

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "../../entities/rockford/rockford.h"
#include "../../loadables/sprites/sprites.h"

void hud_draw(ALLEGRO_FONT *font,
              ROCKFORD *player,
              SPRITES *sprites,
              MAP_DATA *mapData);

#endif