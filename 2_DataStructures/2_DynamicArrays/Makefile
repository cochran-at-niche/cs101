
all: dynamic_array

dynamic_array:
	gcc -Wall -o $@ dynamic_array.c test.c

test: dynamic_array
	./dynamic_array

clean:
	rm dynamic_array
