#include "hud.h"

void hud_draw(ALLEGRO_FONT *font, ROCKFORD *player, int diamondsToWin, int scorePerDiamond)
{
    al_draw_textf(font, al_map_rgb(255, 247, 0), 100, -8, 0, "%d", diamondsToWin);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 250, -8, 0, "%d", scorePerDiamond);
    al_draw_textf(font, al_map_rgb(255, 247, 0), 500, -8, 0, "%02d", player->diamondsObtained);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 900, -8, 0, "%06d", player->score);
}
