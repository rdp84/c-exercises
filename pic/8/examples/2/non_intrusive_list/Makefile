CC	= gcc
# CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -pedantic
CFLAGS	= -Wall
OBJECTS = main.o structs.o list.o
OUTPUT	= -o ../../../../../bin/non_intrusive_list

non_intrusive_list: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTPUT)

main.o: list.h structs.h
structs.o: structs.h
list.o: list.h

.PHONY: clean
clean:
	rm ../../../../../bin/non_intrusive_list $(OBJECTS)
