#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "./libs/display.h"
#include "./libs/utils.h"
#include "./libs/keyboard.h"
#include "./libs/sprites.h"

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    must_init(queue, "queue");

    //DISPLAY
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *buffer = NULL;
    display_init(&display, &buffer);

    //KEYBOARD
    unsigned char key[ALLEGRO_KEY_MAX];
    keyboard_init(key);

    //SPRITES
    SPRITES sprites;
    must_init(al_init_image_addon(), "image addon");
    sprites_init(&sprites);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    bool done = false;
    bool redraw = true;

    ALLEGRO_EVENT event;

    al_start_timer(timer);

    while (true)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            //game logic goes here
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
        }

        if (done)
            break;

        keyboard_update(&event, key);

        if (redraw && al_is_event_queue_empty(queue))
        {
            display_pre_draw(buffer);

            display_post_draw(display, buffer);
            redraw = false;
        }
    }

    sprites_deinit(&sprites);
    display_deinit(display, buffer);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}