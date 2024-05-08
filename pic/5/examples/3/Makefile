CC	= gcc
CFLAGS	= -Wall -fsanitize=address
OBJECTS	= example_3.o
OUTPUT	= -o ../../../../bin/example_3

example3: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

example_3.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_3 $(OBJECTS)
