#include <allegro5/allegro.h>

#define KEY_SEEN 1
#define KEY_RELEASED 2

void keyboard_init(unsigned char *key);

void keyboard_update(ALLEGRO_EVENT *event, unsigned char *key);