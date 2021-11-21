#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "./libs/display.h"
#include "./libs/utils.h"
#include "./libs/keyboard.h"
#include "./libs/sprites.h"
#include "./libs/rockford.h"
#include "./libs/maps.h"
#include "./libs/boulder.h"
#include "./libs/diamond.h"
#include "./libs/dirt.h"
#include "./libs/wall.h"
#include "./libs/steelWall.h"
#include "./libs/memory_alloc.h"
#include "./libs/explosion.h"
#include "./libs/exit.h"
#include "./libs/hud.h"

int main()
{
    //INITIALIZERS
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_font_addon(), "font addon");
    must_init(al_init_ttf_addon(), "ttf addon");

    //TIMER AND QUEUE
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    must_init(queue, "queue");

    //DISPLAY
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *buffer = NULL;
    display_init(&display, &buffer);

    //FONT
    // ALLEGRO_FONT *font = al_create_builtin_font();
    ALLEGRO_FONT *font = al_load_ttf_font("./resources/boulder-dash.ttf", 50, 0);
    must_init(font, "font");

    //KEYBOARD
    unsigned char key[ALLEGRO_KEY_MAX];
    keyboard_init(key);

    //SPRITES
    SPRITES sprites;
    must_init(al_init_image_addon(), "image addon");
    sprites_init(&sprites);

    //EXPLOSIONS
    EXPLOSION explosions[MAX_EXPLOSIONS];
    explosion_init(explosions);

    //MAP
    char loadedMap[MAP_HEIGHT][MAP_WIDTH];
    int diamondsToWin;
    int mapBlinkedFrame = 0;
    ENTITIES_QUANTITIES entitiesQuantities;
    init_entities_count(&entitiesQuantities);
    read_map(loadedMap, "./resources/maps/map1.txt", &entitiesQuantities, &diamondsToWin);

    //PLAYER
    ROCKFORD player;
    rockford_init(&player, loadedMap);

    //ENTITIES
    BOULDER *boulders = NULL;
    DIRT *dirts = NULL;
    DIAMOND *diamonds = NULL;
    STEEL_WALL *steelWalls = NULL;
    WALL *walls = NULL;
    EXIT exits[2];

    rockford_entrance_init(&player, &exits[0]);

    alloc_entities(&entitiesQuantities, &boulders, &diamonds, &dirts, &steelWalls, &walls);

    printf("BOULDER QUANTITY: %d\n", entitiesQuantities.boulder);
    printf("DIRT QUANTITY: %d\n", entitiesQuantities.dirt);
    printf("DIAMOND QUANTITY: %d\n", entitiesQuantities.diamond);
    printf("STEEL WALL QUANTITY: %d\n", entitiesQuantities.steelWall);
    printf("WALL QUANTITY: %d\n", entitiesQuantities.wall);
    printf("DIAMONDS TO WIN: %d\n", diamondsToWin);

    init_map(loadedMap, boulders, diamonds, dirts, steelWalls, walls, &exits[1]);

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
            explosion_update(explosions, loadedMap);
            wall_update(walls, entitiesQuantities.wall, loadedMap);
            boulder_update(boulders, entitiesQuantities.boulder, &player, loadedMap);
            diamond_update(diamonds, entitiesQuantities.diamond, &player, loadedMap);
            dirt_update(dirts, entitiesQuantities.dirt, &player, loadedMap);
            rockford_update(&player, key, loadedMap, explosions);
            rockford_entrance_update(&exits[0], &player);
            exit_update(&exits[1]);
            // print_map(loadedMap);

            if (key[ALLEGRO_KEY_ESCAPE])
                done = true;

            redraw = true;
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

            al_clear_to_color(al_map_rgb(0, 0, 0));

            if (mapBlinkedFrame < 10 && player.diamondsObtained == diamondsToWin)
            {
                mapBlinkedFrame++;
                exits[1].shown = true;
                al_clear_to_color(al_map_rgb(255, 255, 255));
            }

            // al_draw_textf(font, al_map_rgb(255, 255, 255), 0, -8, 0, "X: %d Y:%d", player.x, player.y);

            hud_draw(font, &player, diamondsToWin);

            dirt_draw(dirts, entitiesQuantities.dirt, &sprites);
            steel_wall_draw(steelWalls, entitiesQuantities.steelWall, &sprites);
            wall_draw(walls, entitiesQuantities.wall, &sprites);
            boulder_draw(boulders, entitiesQuantities.boulder, &sprites);
            diamond_draw(diamonds, entitiesQuantities.diamond, &sprites);
            exit_draw(&exits[1], &sprites, true);
            rockford_draw(&player, &sprites);
            exit_draw(&exits[0], &sprites, false);
            explosion_draw(explosions, &sprites);

            display_post_draw(display, buffer);
            redraw = false;
        }
    }

    sprites_deinit(&sprites);
    display_deinit(display, buffer);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_font(font);

    free_entities(&entitiesQuantities, boulders, diamonds, dirts, steelWalls, walls);

    return 0;
}