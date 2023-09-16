CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o random.o newSleep.o
EXEC = box

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c random.h
	$(CC) $(FLAGS) main.c -c

random.o: random.c random.h
	$(CC) $(CFLAGS) random.c -c

newSleep.o: newSleep.c newSleep.h
	$(CC) $(CFLAGS) newSleep.c -c

clean:
	rm $(EXEC) $(OBJ)