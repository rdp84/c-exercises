CC	= gcc
CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
# CFLAGS	= -Wall
OBJECTS	= example_2.o
OUTPUT	= -o ../../../../bin/example_2

example2: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_2.o: node.h

.PHONY: clean
clean:
	rm ../../../../bin/example_2 $(OBJECTS)
