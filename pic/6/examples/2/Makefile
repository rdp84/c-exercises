CC	= gcc
CFLAGS	= -Wall
OBJECTS	= example_2.o
OUTPUT	= -o ../../../../bin/example_2

example2: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_2.o: tree.h

.PHONY: clean
clean:
	rm ../../../../bin/example_2 $(OBJECTS)
