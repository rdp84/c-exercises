DEBUG_FLAGS = -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -Wall -pedantic

all:
	gcc -c lab5.c
	gcc -c parse.c
	gcc -c expr.c
	gcc -o ../../../bin/lab5 lab5.o parse.o expr.o 

sane:
	gcc ${DEBUG_FLAGS} -c lab5.c
	gcc ${DEBUG_FLAGS} -c parse.c
	gcc ${DEBUG_FLAGS} -c expr.c
	gcc ${DEBUG_FLAGS} -o ../../../bin/lab5 lab5.o parse.o expr.o 

clean:
	rm -f ../../../bin/lab5 lab5.o parse.o expr.o 
