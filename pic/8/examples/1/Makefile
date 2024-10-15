CC	= gcc
CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
OBJECTS	= example_1.o
OUTPUT	= -o ../../../../bin/example_1

example1: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_1.o:

.PHONY:	clean
clean:
	rm ../../../../bin/example_1 $(OBJECTS)
