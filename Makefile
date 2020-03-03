#Name: Danniel Licudan
#Project: Lab 1

EXECUTABLES=time-4-baby-and-me
SRC=time-4-baby-and-me.c
OBJ=time-4-baby-and-me.o

CC=gcc
CFLAGS=-g -Wall -Wextra

ALL:$(EXECUTABLES)


$(EXECUTABLES): $(SRC)
				$(CC) $(CFLAGS) -c $(SRC)
				$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
		rm -f $time-4-baby-and-me.c time-4-baby-and-me.o $(OBJ) *~
