CFLAGS = -Wall -Wextra -ansi -pedantic

all: minesweeper

minesweeper: src/*.c
	gcc $(CFLAGS) -o minesweeper src/*.c

