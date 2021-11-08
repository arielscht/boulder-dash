CFLAGS = -Wall

ALLEGRO_LIBS = `pkg-config allegro-5\
			 	allegro_image-5\
				allegro_font-5\
				--libs --cflags`

OBJECTS = utils.o display.o sprites.o keyboard.o rockford.o ./libs/constants.h main.o

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

constants.h: ./libs/constants.h

clean:
	rm -f *.o

purge:	clean
	rm -f boulder-dash
