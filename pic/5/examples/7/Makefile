CC	= gcc
CFLAGS	= -Wall -fsanitize=undefined
OBJECTS	= example_7.o
OUTPUT	= -o ../../../../bin/example_7

example7: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_7.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_7 $(OBJECTS)
