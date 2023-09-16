CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror
OBJ = main.o random.o
EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c random.h
	$(CC) $(FLAGS) main.c -c

random.o: random.c random.h
	$(CC) $(CFLAGS) random.c -c

clean:
	rm $(EXEC) $(OBJ)
