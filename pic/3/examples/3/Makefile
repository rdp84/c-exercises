CC	= gcc
CFLAGS	= -Wall
OBJECTS	= inc.o sort.o example_3.o
OUTPUT	= -o ../../../../bin/example_3

example3: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

inc.o:		example_3.h
sort.o: 	example_3.h
example_3.o: 	example_3.h

.PHONY:	clean
clean:
	rm ../../../../bin/example_3 $(OBJECTS)

