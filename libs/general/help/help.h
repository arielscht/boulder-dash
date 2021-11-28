#ifndef __HELP__
#define __HELP__

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include "../../utils/display/display.h"
#include "../../general/score/score.h"

void help_draw(ALLEGRO_FONT *title, ALLEGRO_FONT *subtitle, ALLEGRO_FONT *text);

void score_draw(ALLEGRO_FONT *title, ALLEGRO_FONT *subtitle, ALLEGRO_FONT *text, int currentScore);

#endif