
all: dynamic_array

test: dynamic_array.h dynamic_array.c test.c
	gcc -Wall -o $@ dynamic_array.c test.c
	./test

clean:
	rm dynamic_array
