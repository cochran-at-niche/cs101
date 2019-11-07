all: dynamic_array

dynamic_array: dynamic_array.h dynamic_array.c test.h test.c
	gcc -Wall -o $@ dynamic_array.c test.c

test: dynamic_array
	./dynamic_array

docker-test:
	docker build --tag=dynamic_array_test .
	docker run --rm -it dynamic_array_test ./dynamic_array

clean:
	rm dynamic_array
