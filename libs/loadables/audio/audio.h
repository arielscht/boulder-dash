#ifndef __AUDIO__
#define __AUDIO__

#include <allegro5/allegro_audio.h>
#include "../../utils/utils/utils.h"

typedef struct SOUNDS
{
    ALLEGRO_AUDIO_STREAM *theme;
    ALLEGRO_SAMPLE *explosion;
    ALLEGRO_SAMPLE *getDiamond;
    ALLEGRO_SAMPLE *diamondFall;
    ALLEGRO_SAMPLE *boulderFall;
    ALLEGRO_SAMPLE *dirt;
    ALLEGRO_SAMPLE *move;
    ALLEGRO_SAMPLE *spawn;
} SOUNDS;

void audio_init(SOUNDS *sounds);

void audio_deinit(SOUNDS *sounds);

#endif