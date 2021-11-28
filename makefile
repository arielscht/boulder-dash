CFLAGS = -Wall

ALLEGRO_LIBS = `pkg-config allegro-5\
			 	allegro_image-5\
				allegro_font-5\
				allegro_ttf-5\
				allegro_audio-5\
				allegro_acodec-5\
				allegro_primitives-5\
				--libs --cflags`

OBJECTS = memoryAlloc.o utils.o display.o sprites.o keyboard.o rockford.o boulder.o dirt.o wall.o steelWall.o diamond.o explosion.o maps.o exit.o hud.o game.o help.o audio.o score.o timer.o ./libs/utils/constants.h main.o

all: boulder-dash

boulder-dash: $(OBJECTS)
	gcc $(OBJECTS) -o boulder-dash $(ALLEGRO_LIBS)

main.o: main.c
	gcc -c main.c $(CFLAGS);

display.o: ./libs/utils/display/display.c ./libs/utils/display/display.h
	gcc -c ./libs/utils/display/display.c $(CFLAGS);

utils.o: ./libs/utils/utils/utils.c ./libs/utils/utils/utils.h
	gcc -c ./libs/utils/utils/utils.c $(CFLAGS);

sprites.o: ./libs/loadables/sprites/sprites.c ./libs/loadables/sprites/sprites.h
	gcc -c ./libs/loadables/sprites/sprites.c $(CFLAGS);

keyboard.o: ./libs/utils/keyboard/keyboard.c ./libs/utils/keyboard/keyboard.h
	gcc -c ./libs/utils/keyboard/keyboard.c $(CFLAGS);

rockford.o: ./libs/entities/rockford/rockford.c ./libs/entities/rockford/rockford.h
	gcc -c ./libs/entities/rockford/rockford.c $(CFLAGS);

maps.o: ./libs/general/maps/maps.c ./libs/general/maps/maps.h
	gcc -c ./libs/general/maps/maps.c $(CFLAGS);

memoryAlloc.o: ./libs/utils/memoryAlloc/memoryAlloc.c ./libs/utils/memoryAlloc/memoryAlloc.h
	gcc -c ./libs/utils/memoryAlloc/memoryAlloc.c $(CFLAGS);

boulder.o: ./libs/entities/boulder/boulder.c ./libs/entities/boulder/boulder.h
	gcc -c ./libs/entities/boulder/boulder.c $(CFLAGS);

dirt.o: ./libs/entities/dirt/dirt.c ./libs/entities/dirt/dirt.h
	gcc -c ./libs/entities/dirt/dirt.c $(CFLAGS);

wall.o: ./libs/entities/wall/wall.c ./libs/entities/wall/wall.h
	gcc -c ./libs/entities/wall/wall.c $(CFLAGS);

steelWall.o: ./libs/entities/steelWall/steelWall.c ./libs/entities/steelWall/steelWall.h
	gcc -c ./libs/entities/steelWall/steelWall.c $(CFLAGS);

diamond.o: ./libs/entities/diamond/diamond.c ./libs/entities/diamond/diamond.h
	gcc -c ./libs/entities/diamond/diamond.c $(CFLAGS);
	
explosion.o: ./libs/entities/explosion/explosion.c ./libs/entities/explosion/explosion.h
	gcc -c ./libs/entities/explosion/explosion.c $(CFLAGS);

exit.o: ./libs/entities/exit/exit.c ./libs/entities/exit/exit.h
	gcc -c ./libs/entities/exit/exit.c $(CFLAGS);

hud.o: ./libs/general/hud/hud.c ./libs/general/hud/hud.h
	gcc -c ./libs/general/hud/hud.c $(CFLAGS);

game.o: ./libs/general/game/game.c ./libs/general/game/game.h
	gcc -c ./libs/general/game/game.c $(CFLAGS);

help.o: ./libs/general/help/help.c ./libs/general/help/help.h
	gcc -c ./libs/general/help/help.c $(CFLAGS);

audio.o: ./libs/loadables/audio/audio.c ./libs/loadables/audio/audio.h
	gcc -c ./libs/loadables/audio/audio.c $(CFLAGS);

score.o: ./libs/general/score/score.c ./libs/general/score/score.h
	gcc -c ./libs/general/score/score.c $(CFLAGS);
	
timer.o: ./libs/general/timer/timer.c ./libs/general/timer/timer.h
	gcc -c ./libs/general/timer/timer.c $(CFLAGS);

constants.h: ./libs/utils/constants.h

clean:
	rm -f *.o

purge:	clean
	rm -f boulder-dash
