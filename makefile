CFLAGS = -Wall

ALLEGRO_LIBS = `pkg-config allegro-5\
			 	allegro_image-5\
				--libs --cflags`

OBJECTS = utils.o display.o main.o

all: boulder-dash

boulder-dash: $(OBJECTS)
	gcc $(OBJECTS) -o boulder-dash $(ALLEGRO_LIBS)

main.o: main.c
	gcc -c main.c $(CFLAGS);

display.o: ./libs/display.c ./libs/display.h
	gcc -c ./libs/display.c $(CFLAGS);

utils.o: ./libs/utils.c ./libs/utils.h
	gcc -c ./libs/utils.c $(CFLAGS);

clean:
	rm -f *.o

purge:	clean
	rm -f boulder-dash
