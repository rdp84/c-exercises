CC      = gcc
CFLAGS  = -Wall
OUTPUT  = -o ../../../../bin/find
OBJECTS = find.o

find: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)
find.o: find.h

.PHONY: clean
clean:
	rm $(OBJECTS)
