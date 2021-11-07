#include <stdio.h>
#include <allegro5/allegro.h>

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}