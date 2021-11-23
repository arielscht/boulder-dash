CFLAGS = -Wall

ALLEGRO_LIBS = `pkg-config allegro-5\
			 	allegro_image-5\
				allegro_font-5\
				allegro_ttf-5\
				--libs --cflags`

OBJECTS = memoryAlloc.o utils.o display.o sprites.o keyboard.o rockford.o boulder.o dirt.o wall.o steelWall.o diamond.o explosion.o maps.o exit.o hud.o game.o ./libs/constants.h main.o

all: boulder-dash

boulder-dash: $(OBJECTS)
	gcc $(OBJECTS) -o boulder-dash $(ALLEGRO_LIBS)

main.o: main.c
	gcc -c main.c $(CFLAGS);

display.o: ./libs/display.c ./libs/display.h
	gcc -c ./libs/display.c $(CFLAGS);

utils.o: ./libs/utils.c ./libs/utils.h
	gcc -c ./libs/utils.c $(CFLAGS);

sprites.o: ./libs/sprites.c ./libs/sprites.h
	gcc -c ./libs/sprites.c $(CFLAGS);

keyboard.o: ./libs/keyboard.c ./libs/keyboard.h
	gcc -c ./libs/keyboard.c $(CFLAGS);

rockford.o: ./libs/rockford.c ./libs/rockford.h
	gcc -c ./libs/rockford.c $(CFLAGS);

maps.o: ./libs/maps.c ./libs/maps.h
	gcc -c ./libs/maps.c $(CFLAGS);

memoryAlloc.o: ./libs/memoryAlloc.c ./libs/memoryAlloc.h
	gcc -c ./libs/memoryAlloc.c $(CFLAGS);

boulder.o: ./libs/boulder.c ./libs/boulder.h
	gcc -c ./libs/boulder.c $(CFLAGS);

dirt.o: ./libs/dirt.c ./libs/dirt.h
	gcc -c ./libs/dirt.c $(CFLAGS);

wall.o: ./libs/wall.c ./libs/wall.h
	gcc -c ./libs/wall.c $(CFLAGS);

steelWall.o: ./libs/steelWall.c ./libs/steelWall.h
	gcc -c ./libs/steelWall.c $(CFLAGS);

diamond.o: ./libs/diamond.c ./libs/diamond.h
	gcc -c ./libs/diamond.c $(CFLAGS);
	
explosion.o: ./libs/explosion.c ./libs/explosion.h
	gcc -c ./libs/explosion.c $(CFLAGS);

exit.o: ./libs/exit.c ./libs/exit.h
	gcc -c ./libs/exit.c $(CFLAGS);

hud.o: ./libs/hud.c ./libs/hud.h
	gcc -c ./libs/hud.c $(CFLAGS);

game.o: ./libs/game.c ./libs/game.h
	gcc -c ./libs/game.c $(CFLAGS);

constants.h: ./libs/constants.h

clean:
	rm -f *.o

purge:	clean
	rm -f boulder-dash
