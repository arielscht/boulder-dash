#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#define KEY_SEEN 1
#define KEY_RELEASED 2

void keyboard_init(unsigned char *key);

void keyboard_update(ALLEGRO_EVENT *event, unsigned char *key);

#endif