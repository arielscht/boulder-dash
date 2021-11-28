#include "keyboard.h"

void keyboard_init(unsigned char *key)
{
    memset(key, 0, sizeof(unsigned char) * ALLEGRO_KEY_MAX);
}

void keyboard_update(ALLEGRO_EVENT *event, unsigned char *key)
{
    switch (event->type)
    {
    case ALLEGRO_EVENT_TIMER:
        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
            key[i] &= KEY_SEEN;
        break;

    case ALLEGRO_EVENT_KEY_DOWN:
        key[event->keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
        break;
    case ALLEGRO_EVENT_KEY_UP:
        key[event->keyboard.keycode] &= KEY_RELEASED;
        break;
    }
}

void handle_keydown(
    ALLEGRO_EVENT event,
    ROCKFORD *player,
    MAP_DATA *mapData,
    GAME_FLAGS *gameFlags)
{
    if (event.keyboard.keycode == ALLEGRO_KEY_H || event.keyboard.keycode == ALLEGRO_KEY_F5)
        gameFlags->helpOpen = !gameFlags->helpOpen;
    if (event.keyboard.keycode == ALLEGRO_KEY_R)
    {
        if (player->lives == 0 && gameFlags->scoreOpen == false)
        {
            gameFlags->cheatActivated = false;
            gameFlags->scoreOpen = true;
            mapData->currentMap = 0;
        }
        else
        {
            player->lives -= 1;
            gameFlags->scoreOpen = false;
            gameFlags->restart = true;
        }
    }
}