#include "boulder.h"

void boulder_draw(BOULDER *boulders, int boulderQuantity, SPRITES *sprites)
{
    for (int i = 0; i < boulderQuantity; i++)
        al_draw_bitmap(
            sprites->boulder,
            boulders[i].x,
            boulders[i].y,
            0);
}
