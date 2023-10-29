CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o map.o player.o goal.o car.o terminal.o 
EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c map.h player.h goal.h car.h terminal.h
	$(CC) $(FLAGS) main.c -c

map.o: map.c map.h terminal.h
	$(CC) $(CFLAGS) map.c -c

player.o: player.c player.h
	$(CC) $(CFLAGS) player.c -c

goal.o: goal.c goal.h
	$(CC) $(CFLAGS) goal.c -c

car.o: car.c car.h
	$(CC) $(CFLAGS) car.c -c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

clean:
	rm $(EXEC) $(OBJ)