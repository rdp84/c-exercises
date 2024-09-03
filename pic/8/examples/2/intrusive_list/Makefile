CC	= gcc
# CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
CFLAG	= -Wall
OBJECTS = main.o coord.o complex.o
OUTPUT	= -o ../../../../../bin/intrusive_list

intrusive_list: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

main.o: coord.h complex.h
coord.o: coord.h
complex.o: complex.h

.PHONY: clean
clean:
	rm ../../../../bin/intrusive_list $(OBJECTS)
