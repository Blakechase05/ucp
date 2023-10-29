CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o terminal.o
EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c terminal.h
	$(CC) $(FLAGS) main.c -c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

clean:
	rm $(EXEC) $(OBJ)