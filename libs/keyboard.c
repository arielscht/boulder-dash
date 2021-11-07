#include <allegro5/allegro_image.h>
#include <stdio.h>
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