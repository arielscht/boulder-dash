#include "exit.h"

void thunder_update(ROCKFORD *player, MAP_DATA *mapData, EXIT *exit, SOUNDS *sounds)
{
    if (mapData->blinkedFrame < 10 && player->diamondsObtained == mapData->diamondsToWin)
    {
        if (mapData->blinkedFrame == 0)
            al_play_sample(sounds->spawn, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        mapData->blinkedFrame += 1;
        exit->shown = true;
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }
}

void exit_update(EXIT *exit, ROCKFORD *player, bool *restart, MAP_DATA *mapData)
{
    if (!exit->shown)
        return;

    exit->delay++;

    if (exit->delay % 30 != 0)
        return;

    exit->sourceX += SPRITE_WIDTH;

    if (exit->sourceX == SPRITE_WIDTH * 2)
        exit->sourceX = 0;

    if (exit->x == player->x && exit->y == player->y)
    {
        int obtainedScore = player->score + mapData->levelScore - player->previousScore;
        if (obtainedScore / 500 >= 1)
            player->lives += obtainedScore / 500;
        player->previousScore = player->score + mapData->levelScore;
        *restart = true;
        mapData->currentMap += 1;
    }
}

void exit_draw(EXIT *exit, SPRITES *sprites, bool isExit)
{
    if (!exit->shown && !isExit)
        return;

    al_draw_bitmap_region(sprites->exit,
                          exit->sourceX,
                          0,
                          SPRITE_WIDTH,
                          SPRITE_HEIGHT,
                          exit->x,
                          exit->y, 0);
}

void rockford_entrance_init(ROCKFORD *player, EXIT *entrance)
{
    entrance->x = player->x;
    entrance->y = player->y;
    entrance->shown = true;
    entrance->delay = 0;
    entrance->sourceX = 0;
}

void rockford_entrance_update(EXIT *entrance, ROCKFORD *player, SOUNDS *sounds)
{
    if (!entrance->shown)
        return;

    entrance->delay++;

    if (entrance->delay % 20 != 0)
        return;

    entrance->sourceX += SPRITE_WIDTH;

    if (entrance->sourceX == SPRITE_WIDTH * 2)
        entrance->sourceX = 0;

    if (entrance->delay % 180 == 0)
    {
        al_play_sample(sounds->spawn, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        entrance->shown = false;
        player->entering = false;
    }
}