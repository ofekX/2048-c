CC=gcc
OBJS=main.o game.o utilityFunctions.o
EXEC=game2048
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c
game.o: game.c game.h utilityFunctions.h
utilityFunctions.o: utilityFunctions.c utilityFunctions.h

clean:
	rm -f $(EXEC) $(OBJS)
