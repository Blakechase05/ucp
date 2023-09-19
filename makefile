CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o init.o update.o random.o newSleep.o terminal.o
EXEC = traffic

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c init.h update.h random.h newSleep.h terminal.h
	$(CC) $(FLAGS) main.c -c

init.o: init.c init.h
	$(CC) $(CFLAGS) init.c -c

update.o: update.c update.h
	$(CC) $(CFLAGS) update.c -c

random.o: random.c random.h
	$(CC) $(CFLAGS) random.c -c

newSleep.o: newSleep.c newSleep.h
	$(CC) $(CFLAGS) newSleep.c -c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

clean:
	rm $(EXEC) $(OBJ)