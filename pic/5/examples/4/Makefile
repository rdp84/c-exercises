CC	= gcc
CFLAGS	= -Wall -fsanitize=memory
OBJECTS	= example_4.o
OUTPUT	= -o ../../../../bin/example_4

example4: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

example_4.o:

.PHONY: clean
clean:
	rm ../../../../bin/example_4 $(OBJECTS)
