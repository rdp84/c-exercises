CC	= gcc
CFLAGS	= -Wall
OUTPUT 	= -o ../../../../bin/tail
OBJECTS = main.o lines.o tail.o

tail: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

main.o:	  lines.h tail.h
lines.o:  lines.h
tail.o:   tail.h

.PHONE: clean
clean:
	rm $(OBJECTS)
