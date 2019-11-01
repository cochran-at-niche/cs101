
all: test

build: dynamic_array.h dynamic_array.c test.c
	gcc -Wall -o $@ dynamic_array.c test.c

test: build
	./test

clean:
	rm dynamic_array
