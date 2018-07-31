CC = gcc
CFLAGS = -l ncurses -I $(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c
		  # \ $(SRCDIR)utils/*.c

all: breach #run clean

breach: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o ./bin/search

run:
	./bin/breach

clean:
	rm ./bin/breach