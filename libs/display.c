#include <allegro5/allegro.h>
#include "display.h"
#include "utils.h"

void display_init(ALLEGRO_DISPLAY **display, ALLEGRO_BITMAP **buffer)
{
    *display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    must_init(display, "display");

    *buffer = al_create_bitmap(BUFFER_WIDTH, BUFFER_HEIGHT);
    must_init(buffer, "bitmap buffer");
}

void display_deinit(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *buffer)
{
    al_destroy_display(display);
    al_destroy_bitmap(buffer);
}

void display_pre_draw(ALLEGRO_BITMAP *buffer)
{
    al_set_target_bitmap(buffer);
}

void display_post_draw(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *buffer)
{
    al_set_target_backbuffer(display);
    al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_WIDTH, BUFFER_HEIGHT, 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0);

    al_flip_display();
}
