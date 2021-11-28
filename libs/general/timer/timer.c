#include "timer.h"

void timer_update(int *frameCounter, ROCKFORD *player, MAP_DATA *mapData)
{
    if (player->entering)
        return;

    *frameCounter += 1;
    if (mapData->levelTime > 0)
    {
        if (*frameCounter % 60 == 0)
            mapData->levelTime -= 1;
    }
    else if (player->alive)
    {
        player->lives -= 1;
        player->alive = false;
    }
}