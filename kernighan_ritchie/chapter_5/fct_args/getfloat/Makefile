CC      = gcc
CCFLAGS = -Wall
OUT     = -o ../../../../bin/getfloat
OBJECTS = getfloat.o char.o main.o

getfloat: $(OBJECTS)
		$(CC) $(CCFLAGS) $(OUT) $(OBJECTS)

getfloat.o:  getfloat.h
char.o:      getfloat.h
main.o:      getfloat.h

.PHONY: clean
clean:
		-rm $(OBJECTS)
