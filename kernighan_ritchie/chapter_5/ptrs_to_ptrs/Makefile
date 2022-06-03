CC      = gcc
CFLAGS  = -Wall
OUTPUT  = -o ../../../bin/sort
OBJECTS = main.o lines.o alloc.o sort.o

sort: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

main.o:  lines.h sort.h
lines.o: lines.h alloc.h
alloc.o: alloc.h
sort.o:  sort.h

.PHONY: clean
clean:
	rm $(OBJECTS)
