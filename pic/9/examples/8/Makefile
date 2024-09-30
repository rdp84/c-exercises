CC	= gcc
CFLAGS	= -Wall
OBJECTS	= example_8.o unit.o
OUTPUT	= -o ../../../../bin/example_8

example8: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

example_8.o: unit.h
unit.o: unit.h

.PHONY: clean
clean:
	rm $(OBJECTS) ../../../../bin/example_8
