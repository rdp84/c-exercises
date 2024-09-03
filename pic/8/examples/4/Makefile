CC	= gcc
# CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
CFLAGS	= -Wall
OBJECTS	= main.o structs.o
OUTPUT	= -o ../../../../bin/data_vec

example4: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)
main.o: structs.h
structs.o: structs.h

.PHONY: clean
clean:
	rm ../../../../bin/data_vec $(OBJECTS)
