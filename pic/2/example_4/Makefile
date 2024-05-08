CC      = gcc
CFLAGS  = -Wall
OBJECTS = example4a.o example4b.o
OUTPUT  = -o ../../../bin/example4

example4: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

example4a.o: example4.h
example4b.o: example4.h

.PHONY: clean
clean:
	rm ../../../bin/example4 $(OBJECTS)


