#include "audio.h"

void audio_init(SOUNDS *sounds)
{
    sounds->theme = al_load_audio_stream("./resources/sounds/theme.ogg", 2, 2048);
    must_init(sounds->theme, "theme song");

    sounds->move = al_load_sample("./resources/sounds/move.wav");
    must_init(sounds->move, "rockford move sound");

    sounds->spawn = al_load_sample("./resources/sounds/spawn.wav");
    must_init(sounds->spawn, "rockford spawn sound");

    sounds->dirt = al_load_sample("./resources/sounds/dirt-effect.wav");
    must_init(sounds->dirt, "dirt sound");

    sounds->boulderFall = al_load_sample("./resources/sounds/boulder.wav");
    must_init(sounds->boulderFall, "boulder sound");

    sounds->diamondFall = al_load_sample("./resources/sounds/diamond-fall.wav");
    must_init(sounds->diamondFall, "diamond fall sound");

    sounds->getDiamond = al_load_sample("./resources/sounds/diamond.wav");
    must_init(sounds->getDiamond, "get diamond sound");

    sounds->explosion = al_load_sample("./resources/sounds/explosion.wav");
    must_init(sounds->explosion, "explosion sound");
};

void audio_deinit(SOUNDS *sounds)
{
    al_destroy_audio_stream(sounds->theme);
    al_destroy_sample(sounds->move);
    al_destroy_sample(sounds->spawn);
    al_destroy_sample(sounds->dirt);
    al_destroy_sample(sounds->boulderFall);
    al_destroy_sample(sounds->diamondFall);
    al_destroy_sample(sounds->getDiamond);
    al_destroy_sample(sounds->explosion);
};