PROGS = fila
CC = gcc
CFLAGS = -Wall -g
objects = main.o libfila.o aux.o

game: $(objects)
	$(CC) $(CFLAGS) $(objects) -o $(PROGS)

main.o: main.c libfila.h
	$(CC) $(CFLAGS) -c main.c

libfila.o: libfila.c libfila.h
	$(CC) $(CFLAGS) -c libfila.c

aux.o: aux.c aux.h
	$(CC) $(CFLAGS) -c aux.c

clean:
	-rm -f *~ *.o

purge: clean
	-rm -f $(PROGS)