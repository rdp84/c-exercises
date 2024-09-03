CC	= gcc
# CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
CFLAGS	= -Wall
OBJECTS	= structs.o main.o
OUTPUT = -o ../../../../bin/array_of_structs

example3: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

structs.o: structs.h
main.o: structs.h

.PHONY: clean
clean:
	rm ../../../../bin/array_of_structs $(OBJECTS)
