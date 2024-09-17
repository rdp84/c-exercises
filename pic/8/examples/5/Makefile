CC	= gcc
CFLAGS	= -Wall
OBJECTS = matrix.o main.o
OUTPUT	= -o ../../../../bin/matrix

example5: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

matrix.o: matrix.h
main.o: matrix.h

.PHONY: clean
clean:
	rm $(OBJECTS) ../../../../bin/matrix
