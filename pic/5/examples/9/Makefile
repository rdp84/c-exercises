CC	= gcc
CFLAGS	= -Wall -fsanitize=undefined
OBJECTS	= example_9.o
OUTPUT	= -o ../../../../bin/example_9

example9: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_9.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_9 $(OBJECTS)
