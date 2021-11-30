#include "exit.h"

//draws and updates the thunder when player unlocks the exit
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

//update the exit
void exit_update(EXIT *exit, ROCKFORD *player, GAME_FLAGS *gameFlags, MAP_DATA *mapData)
{
    if (!exit->shown)
        return;

    exit->delay++;

    if (exit->delay % 30 != 0)
        return;

    //update the exit sprite
    exit->sourceX += SPRITE_WIDTH;

    if (exit->sourceX == SPRITE_WIDTH * 2)
        exit->sourceX = 0;

    //handle game finish when player is in the exit
    if (exit->x == player->x && exit->y == player->y)
    {
        //give an extra life to the player if it got 500 or more score in that level
        int obtainedScore = player->score + mapData->levelScore - player->previousScore;
        if (obtainedScore / 500 >= 1)
            player->lives += obtainedScore / 500;
        player->previousScore = player->score + mapData->levelScore;
        player->score = player->previousScore;
        //open the score menu if the player finished the whole game
        if (mapData->currentMap == MAP_QUANTITY - 1)
        {
            save_score(player->score);
            mapData->currentMap = 0;
            //To cause the score to restore
            player->lives = -1;
            gameFlags->scoreOpen = true;
            gameFlags->cheatActivated = false;
        }
        //otherwise just start the next level
        else
        {
            gameFlags->restart = true;
            mapData->currentMap += 1;
        }
    }
}

//draw the exit
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

//init the rockford entrance
void rockford_entrance_init(ROCKFORD *player, EXIT *entrance)
{
    entrance->x = player->x;
    entrance->y = player->y;
    entrance->shown = true;
    entrance->delay = 0;
    entrance->sourceX = 0;
}

//update the rockford entrance
void rockford_entrance_update(EXIT *entrance, ROCKFORD *player, SOUNDS *sounds)
{
    if (!entrance->shown)
        return;

    entrance->delay++;

    if (entrance->delay % 20 != 0)
        return;

    //updates the entrance sprite
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