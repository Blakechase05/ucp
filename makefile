CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o
EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c
	$(CC) $(FLAGS) main.c -c

clean:
	rm $(EXEC) $(OBJ)
