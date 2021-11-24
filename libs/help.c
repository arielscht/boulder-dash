#include "help.h"

void help_draw(ALLEGRO_FONT *title, ALLEGRO_FONT *subtitle, ALLEGRO_FONT *text)
{
    al_draw_filled_rectangle(0, 0, 1280, 736, al_map_rgba(0, 0, 0, 100));
    al_draw_filled_rounded_rectangle(320, 100, 960, 636, 10, 10, al_map_rgba(184, 184, 184, 255));
    al_draw_text(title, al_map_rgb(0, 0, 0), BUFFER_WIDTH / 2, 120, ALLEGRO_ALIGN_CENTRE, "HELP");
    al_draw_multiline_text(
        subtitle,
        al_map_rgb(0, 0, 0),
        BUFFER_WIDTH / 2, 170,
        640, 20,
        ALLEGRO_ALIGN_CENTRE, "Here you find all the instructions that you need in order to play");
    al_draw_multiline_text(
        text,
        al_map_rgb(0, 0, 0),
        340, 240,
        600, 20,
        0, "Guide Rockford through the caves, but be careful with the boulders and the enemies and try to get as many diamonds as you can.");
    al_draw_multiline_text(
        text,
        al_map_rgb(0, 0, 0),
        340, 310,
        600, 20,
        0, "- Use the arrow keys or W A S D to control your hero.");
    al_draw_multiline_text(
        text,
        al_map_rgb(0, 0, 0),
        340, 360,
        600, 20,
        0, "- Press R to restart your level.");
    al_draw_text(
        text,
        al_map_rgb(0, 0, 0),
        (BUFFER_WIDTH / 2) + 40, 610,
        0, "Press h or f5 to play");
}