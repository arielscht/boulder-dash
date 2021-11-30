#include "hud.h"

//draw the hud
void hud_draw(ALLEGRO_FONT *font, ROCKFORD *player, SPRITES *sprites, MAP_DATA *mapData)
{
    al_draw_textf(font, al_map_rgb(255, 247, 0), 10, -8, 0, "%d", mapData->diamondsToWin);
    al_draw_scaled_bitmap(sprites->diamondIcon, 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT / 2, 105, -2, SPRITE_WIDTH + 15, SPRITE_HEIGHT, 0);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 155, -8, 0, "%d", mapData->scorePerDiamond);
    al_draw_bitmap(sprites->rockford[ROCKFORD_STAND_STILL], 300, 0, 0);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 340, -8, 0, "%d", player->lives >= 0 ? player->lives : 0);
    al_draw_textf(font, al_map_rgb(255, 247, 0), 500, -8, 0, "%02d", player->diamondsObtained);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 800, -8, ALLEGRO_ALIGN_CENTRE, "%d", mapData->levelTime);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 980, -8, 0, "%06d", player->score);
}
