#include "hud.h"

void hud_draw(ALLEGRO_FONT *font, ROCKFORD *player, SPRITES *sprites, int diamondsToWin, int scorePerDiamond)
{
    al_draw_textf(font, al_map_rgb(255, 247, 0), 10, -8, 0, "%d", diamondsToWin);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 160, -8, 0, "%d", scorePerDiamond);
    al_draw_bitmap(sprites->rockford[ROCKFORD_STAND_STILL], 300, 0, 0);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 340, -8, 0, "%d", player->lives >= 0 ? player->lives : 0);
    al_draw_textf(font, al_map_rgb(255, 247, 0), 500, -8, 0, "%02d", player->diamondsObtained);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 980, -8, 0, "%06d", player->score);
}
