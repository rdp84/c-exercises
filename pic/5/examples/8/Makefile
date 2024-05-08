CC	= gcc
CFLAGS	= -Wall -fsanitize=undefined
OBJECTS	= example_8.o
OUTPUT	= -o ../../../../bin/example_8

example8: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_8.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_8 $(OBJECTS)
