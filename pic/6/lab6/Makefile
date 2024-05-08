# The debug flags to enable the sanitizers
DEBUG_FLAGS = -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -Wall -pedantic

all: 
	gcc -Wall -pedantic -c lab6.c
	gcc -Wall -pedantic -c graph.c 
	gcc -o ../../../bin/lab6 lab6.o graph.o

clang:
	clang -Wall -pedantic -c lab6.c
	clang -Wall -pedantic -c graph.c 
	clang -o ../../../bin/lab6 lab6.o graph.o

sane:
	gcc ${DEBUG_FLAGS} -c lab6.c
	gcc ${DEBUG_FLAGS} -c graph.c 
	gcc ${DEBUG_FLAGS} -o ../../../bin/lab6 lab6.o graph.o

clean:
	rm -f lab6.o graph.o ../../../bin/lab6
