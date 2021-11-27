#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
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
#include "./libs/memoryAlloc.h"
#include "./libs/explosion.h"
#include "./libs/exit.h"
#include "./libs/hud.h"
#include "./libs/game.h"
#include "./libs/help.h"
#include "./libs/audio.h"

int main()
{
    //INITIALIZERS
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_font_addon(), "font addon");
    must_init(al_init_ttf_addon(), "ttf addon");
    must_init(al_init_primitives_addon(), "primitives addon");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(50), "reserve samples");

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
    ALLEGRO_FONT *font = al_load_ttf_font("./resources/fonts/boulder-dash.ttf", 50, 0);
    ALLEGRO_FONT *menuTitleFont = al_load_ttf_font("./resources/fonts/press-start.ttf", 35, 0);
    ALLEGRO_FONT *menuSubtitleFont = al_load_ttf_font("./resources/fonts/press-start.ttf", 15, 0);
    ALLEGRO_FONT *menuTextFont = al_load_ttf_font("./resources/fonts/press-start.ttf", 12, 0);
    must_init(font, "font");

    //AUDIO
    SOUNDS sounds;
    audio_init(&sounds);
    al_set_audio_stream_playmode(sounds.theme, ALLEGRO_PLAYMODE_LOOP);
    al_set_audio_stream_gain(sounds.theme, 0.5);
    al_attach_audio_stream_to_mixer(sounds.theme, al_get_default_mixer());

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
    MAP_DATA mapData;
    int mapBlinkedFrame = 0;
    ENTITIES_QUANTITIES entitiesQuantities;

    //PLAYER
    ROCKFORD player;
    rockford_init_score(&player);

    //ENTITIES
    BOULDER *boulders = NULL;
    DIRT *dirts = NULL;
    DIAMOND *diamonds = NULL;
    STEEL_WALL *steelWalls = NULL;
    WALL *walls = NULL;
    EXIT exits[2];

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    bool done = false;
    bool redraw = true;
    bool restart = true;
    bool helpOpen = false;

    char maps[MAP_QUANTITY][50] = {"./resources/maps/map1.txt", "./resources/maps/map2.txt"};
    int currentMap = 0;

    ALLEGRO_EVENT event;

    al_start_timer(timer);

    while (true)
    {
        al_wait_for_event(queue, &event);

        if (restart)
        {
            free_entities(&boulders, &diamonds, &dirts, &steelWalls, &walls);

            start_game(loadedMap,
                       &mapData,
                       &entitiesQuantities,
                       maps[currentMap],
                       &player,
                       &boulders,
                       &dirts,
                       &diamonds,
                       &steelWalls,
                       &walls,
                       &exits[0],
                       &exits[1]);

            mapBlinkedFrame = 0;
            restart = false;
        }

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            //game logic goes here

            if (!helpOpen)
            {
                explosion_update(explosions, loadedMap);
                wall_update(walls, entitiesQuantities.wall, loadedMap);
                boulder_update(boulders, entitiesQuantities.boulder, &player, loadedMap, &sounds);
                diamond_update(diamonds, entitiesQuantities.diamond, &player, loadedMap, &mapData, &sounds);
                dirt_update(dirts, entitiesQuantities.dirt, &player, loadedMap, &sounds);
                rockford_update(&player, key, loadedMap, explosions, &restart, &sounds, exits[1].shown, &currentMap);
                rockford_entrance_update(&exits[0], &player, &sounds);
                exit_update(&exits[1], &player, &restart, &currentMap, &mapData);
                // print_map(loadedMap);
            }

            if (key[ALLEGRO_KEY_ESCAPE])
                done = true;

            if (key[ALLEGRO_KEY_R])
                restart = true;

            redraw = true;
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_H || event.keyboard.keycode == ALLEGRO_KEY_F5)
                helpOpen = !helpOpen;
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

            if (mapBlinkedFrame < 10 && player.diamondsObtained == mapData.diamondsToWin)
            {
                if (mapBlinkedFrame == 0)
                    al_play_sample(sounds.spawn, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                mapBlinkedFrame++;
                exits[1].shown = true;
                al_clear_to_color(al_map_rgb(255, 255, 255));
            }

            hud_draw(font, &player, &sprites, &mapData);
            dirt_draw(dirts, entitiesQuantities.dirt, &sprites);
            steel_wall_draw(steelWalls, entitiesQuantities.steelWall, &sprites);
            wall_draw(walls, entitiesQuantities.wall, &sprites);
            boulder_draw(boulders, entitiesQuantities.boulder, &sprites);
            diamond_draw(diamonds, entitiesQuantities.diamond, &sprites);
            exit_draw(&exits[1], &sprites, true);
            rockford_draw(&player, &sprites);
            exit_draw(&exits[0], &sprites, false);
            explosion_draw(explosions, &sprites);
            if (helpOpen)
                help_draw(menuTitleFont, menuSubtitleFont, menuTextFont);

            display_post_draw(display, buffer);
            redraw = false;
        }
    }

    sprites_deinit(&sprites);
    audio_deinit(&sounds);
    display_deinit(display, buffer);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_font(font);
    al_destroy_font(menuTitleFont);
    al_destroy_font(menuSubtitleFont);
    al_destroy_font(menuTextFont);

    free_entities(&boulders, &diamonds, &dirts, &steelWalls, &walls);

    return 0;
}