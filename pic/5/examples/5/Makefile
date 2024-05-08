CC	= gcc
CFLAGS	= -Wall -fsanitize=memory
OBJECTS	= example_5.o
OUTPUT	= -o ../../../../bin/example_5

example5: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_5.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_5 $(OBJECTS)

