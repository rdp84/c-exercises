CC	= gcc
CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
# CFLAGS	= -Wall
OBJECTS	= example_3.o gc.o
OUTPUT	= -o ../../../../bin/example_3


example3: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_3.o: gc.h
gc.o: gc.h

.PHONY: clean
clean:
	rm ../../../../bin/example_3 $(OBJECTS)
