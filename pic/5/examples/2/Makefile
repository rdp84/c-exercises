CC	= gcc
CFLAGS	= -Wall -fsanitize=address
OBJECTS	= example_2.o
OUTPUT	= -o ../../../../bin/example_2

example2: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

example_2.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_2 $(OBJECTS)

