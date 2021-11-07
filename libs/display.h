#include <allegro5/allegro.h>

#define BUFFER_WIDTH 320
#define BUFFER_HEIGHT 184

#define DISPLAY_SCALE 3.9
#define DISPLAY_WIDTH (BUFFER_WIDTH * DISPLAY_SCALE)
#define DISPLAY_HEIGHT (BUFFER_HEIGHT * DISPLAY_SCALE)

void display_init(ALLEGRO_DISPLAY **display, ALLEGRO_BITMAP **buffer);
void display_deinit(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *buffer);
void display_pre_draw(ALLEGRO_BITMAP *buffer);
void display_post_draw(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *buffer);