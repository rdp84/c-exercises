CC		= gcc
# CFLAGS	= -Wall -fsanitize=address -fsanitize=undefined
CFLAGS	= -Wall
OBJECTS	= lab7.o re.o
OUTPUT 	= -o ../../../bin/lab7

lab7: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

lab7.o: re.h
re.o: re.h

.PHONY: clean
clean:
	rm ../../../bin/lab7 $(OBJECTS)
