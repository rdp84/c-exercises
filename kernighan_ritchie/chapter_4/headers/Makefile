OBJECTS = getch.o getop.o \
		main.o stack.o

# Our goal recipe
reverse_polish: $(OBJECTS)
		cc -lm -o reverse_polish $(OBJECTS)

# Implicit rules - make will use the recipe cc -c $(obj.c) -o $(obj.o)
# by default so we can omit that. When a .c file is used in this way
# it is also automatically added to the list of prerequisites so we
# can omit the .c files from there as well.
# This leaves us with:
getch.o: calc.h
getop.o: calc.h
main.o: calc.h
stack.o: calc.h

# Rather than:
# getch.o: calc.h getch.c
#        cc -c getch.c

# Can also group by prerequisites.
# This is more compact but some find it clearer to have
# information on each target in one place.
# So you can have:
# $(OBJECTS): calc.h


# Prevent make from becoming confused by an actual file called clean
# and continue in spite of errors from rm
.PHONY: clean
clean:
		-rm $(OBJECTS)

.PHONY: tags
tags:
		ctags -e -R .
