# Copyright 2021 - 2022 Omer Tarik Ilhan 314CA

CFLAGS=-g -Wall -std=c99
CFILES=utils.h sort_deck.c split.c merge.c reverse.c shuffle.c exit.c add_stuff.c dll_base.c show.c structures.h errors.c deck_info.c delete_stuff.c

build:
	gcc  $(CFLAGS) tema1.c $(CFILES) -o tema1
run:
	valgrind --show-leak-kinds=all --leak-check=full ./tema1
clean:
	rm tema1
