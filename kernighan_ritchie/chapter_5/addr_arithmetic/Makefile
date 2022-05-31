CC      = gcc
CFLAGS  = -Wall
OUTPUT  = -o ../../../bin/alloc
OBJECTS = main.o alloc.o

alloc: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

main.o:  alloc.h
alloc.o: alloc.h

.PHONY: clean
clean:
	rm $(OBJECTS)

