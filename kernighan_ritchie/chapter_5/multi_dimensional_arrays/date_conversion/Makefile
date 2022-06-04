CC       = gcc
CFLAGS   = -Wall
OUTPUT   = -o ../../../../bin/date_conversion
OBJECTS  = main.o date.o

date_conversion: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

main.o: date.h
date.o: date.h

.PHONY: clean
clean:
	rm $(OBJECTS)
