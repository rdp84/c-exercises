CC      = gcc
CCFLAGS = -Wall
OUT     = -o ../../../../bin/getint
OBJECTS = getint.o char.o main.o

getint: $(OBJECTS)
		$(CC) $(CCFLAGS) $(OUT) $(OBJECTS)

getint.o: getint.h
char.o:   getint.h
main.o:   getint.h

.PHONY: clean
clean:
		-rm $(OBJECTS)
