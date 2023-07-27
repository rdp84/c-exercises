CC       = gcc
CFLAGS   = -Wall
OUTPUT   = -o ../../../../bin/expr
OBJECTS  = getch.o getop.o main.o stack.o

expr: $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUT) $(OBJECTS)

getch.o: calc.h
getop.o: calc.h
main.o: calc.h
stack.o: calc.h

.PHONY: clean
clean:
	-rm $(OBJECTS)

.PHONY: tags
tags:
	ctags -e -R .

