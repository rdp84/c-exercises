CC	= gcc
CFLAGS	= -Wall -fsanitize=address
OBJECTS	= example_1.o
OUTPUT	= -o ../../../../bin/example_1

example1: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

example_1.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_1 $(OBJECTS)
