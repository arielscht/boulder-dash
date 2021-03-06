#include "help.h"

//Draw the help menu
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
        0, "- Press R to restart your level, but be aware that you will lose one life.");
    al_draw_multiline_text(
        text,
        al_map_rgb(0, 0, 0),
        340, 410,
        600, 20,
        0, "- Press K L N together to get 5 extra lives, but you can use it only once.");
    al_draw_text(
        text,
        al_map_rgb(0, 0, 0),
        (BUFFER_WIDTH / 2), 580,
        ALLEGRO_ALIGN_CENTRE, "Developed by Ariel Evaldt Schmitt");
    al_draw_text(
        text,
        al_map_rgb(0, 0, 0),
        (BUFFER_WIDTH / 2) + 40, 610,
        0, "Press H or F5 to play");
}

//Draw the score menu
void score_draw(ALLEGRO_FONT *title, ALLEGRO_FONT *subtitle, ALLEGRO_FONT *text, int currentScore)
{
    al_draw_filled_rectangle(0, 0, 1280, 736, al_map_rgba(0, 0, 0, 100));
    al_draw_filled_rounded_rectangle(320, 100, 960, 636, 10, 10, al_map_rgba(184, 184, 184, 255));
    al_draw_text(title, al_map_rgb(0, 0, 0), BUFFER_WIDTH / 2, 120, ALLEGRO_ALIGN_CENTRE, "BEST SCORES");
    al_draw_textf(title, al_map_rgb(0, 0, 0), BUFFER_WIDTH / 2, 200, ALLEGRO_ALIGN_CENTRE, "%d", currentScore);

    int savedScore[MAX_SCORE_STORED];
    int scoreQtd = 0;

    read_score(savedScore, &scoreQtd);

    for (int i = 0; i < scoreQtd; i++)
    {
        al_draw_textf(
            title,
            al_map_rgb(0, 0, 0),
            530, 280 + i * (60),
            0, "%d. %d", i + 1, savedScore[i]);
    }

    al_draw_text(
        text,
        al_map_rgb(0, 0, 0),
        400, 600,
        0, "Press R to restart");
    al_draw_text(
        text,
        al_map_rgb(0, 0, 0),
        650, 600,
        0, "Press ESC to leave");
}