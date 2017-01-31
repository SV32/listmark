CC=clang-3.9
CFLAGS=-O2 -pipe -std=c11 -pedantic

all: main

main: main.o list.o
	$(CC) $(CFLAGS) main.o list.o -o clist

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
list.o: list.c
	$(CC) $(CFLAGS) -c list.c
clean:
	rm clist *.o
