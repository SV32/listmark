CC=clang-3.9
CFLAGS=-O2 -pipe -std=c11 -pedantic

all: main

main: main.o
	$(CC) $(CFLAGS) main.o -o clist

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm clist *.o
