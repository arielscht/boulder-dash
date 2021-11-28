#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "./libs/utils/display/display.h"
#include "./libs/utils/utils/utils.h"
#include "./libs/utils/keyboard/keyboard.h"
#include "./libs/utils/memoryAlloc/memoryAlloc.h"
#include "./libs/entities/rockford/rockford.h"
#include "./libs/entities/boulder/boulder.h"
#include "./libs/entities/diamond/diamond.h"
#include "./libs/entities/dirt/dirt.h"
#include "./libs/entities/wall/wall.h"
#include "./libs/entities/steelWall/steelWall.h"
#include "./libs/entities/explosion/explosion.h"
#include "./libs/entities/exit/exit.h"
#include "./libs/general/maps/maps.h"
#include "./libs/general/hud/hud.h"
#include "./libs/general/game/game.h"
#include "./libs/general/help/help.h"
#include "./libs/general/score/score.h"
#include "./libs/general/timer/timer.h"
#include "./libs/loadables/sprites/sprites.h"
#include "./libs/loadables/audio/audio.h"

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
    int frameCount = 0;

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
    char maps[MAP_QUANTITY][50] = {"./resources/maps/map1.txt", "./resources/maps/map2.txt"};
    char loadedMap[MAP_HEIGHT][MAP_WIDTH];
    MAP_DATA mapData;
    mapData.currentMap = 0;
    mapData.blinkedFrame = 0;
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

    GAME_FLAGS gameFlags;
    init_game_flags(&gameFlags);

    ALLEGRO_EVENT event;

    al_start_timer(timer);

    while (true)
    {
        al_wait_for_event(queue, &event);

        if (gameFlags.restart)
        {
            free_entities(&boulders, &diamonds, &dirts, &steelWalls, &walls);

            start_game(loadedMap,
                       &mapData,
                       &entitiesQuantities,
                       maps[mapData.currentMap],
                       &player,
                       &boulders,
                       &dirts,
                       &diamonds,
                       &steelWalls,
                       &walls,
                       &exits[0],
                       &exits[1]);

            frameCount = 0;
            mapData.blinkedFrame = 0;
            gameFlags.restart = false;
        }

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            //game logic goes here

            if (!gameFlags.helpOpen && !gameFlags.scoreOpen)
            {
                explosion_update(explosions, loadedMap);
                wall_update(walls, entitiesQuantities.wall, loadedMap);
                boulder_update(boulders, entitiesQuantities.boulder, &player, loadedMap, &sounds);
                diamond_update(diamonds, entitiesQuantities.diamond, &player, loadedMap, &mapData, &sounds);
                dirt_update(dirts, entitiesQuantities.dirt, &player, loadedMap, &sounds);
                rockford_update(&player, key, loadedMap, explosions, &gameFlags, &sounds, exits[1].shown, &mapData);
                rockford_entrance_update(&exits[0], &player, &sounds);
                exit_update(&exits[1], &player, &gameFlags, &mapData);
                timer_update(&frameCount, &player, &mapData);
                // print_map(loadedMap);
                handle_cheatcode(key, &player, &gameFlags);
            }

            gameFlags.redraw = true;
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            handle_keydown(event, &player, &mapData, &gameFlags);
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            gameFlags.done = true;
        }

        if (gameFlags.done)
            break;

        keyboard_update(&event, key);

        if (gameFlags.redraw && al_is_event_queue_empty(queue))
        {
            display_pre_draw(buffer);
            al_clear_to_color(al_map_rgb(0, 0, 0));

            thunder_update(&player, &mapData, &exits[1], &sounds);
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
            if (gameFlags.helpOpen)
                help_draw(menuTitleFont, menuSubtitleFont, menuTextFont);
            if (gameFlags.scoreOpen)
                score_draw(menuTitleFont, menuSubtitleFont, menuTextFont, player.score);

            display_post_draw(display, buffer);
            gameFlags.redraw = false;
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