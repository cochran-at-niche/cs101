
all: dynamic_array

dynamic_array: dynamic_array.h dynamic_array.c test.h test.c
	gcc -Wall -o $@ dynamic_array.c test.c

test: dynamic_array
	./dynamic_array

clean:
	rm dynamic_array
