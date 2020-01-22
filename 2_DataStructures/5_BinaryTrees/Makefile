DIR = $(shell pwd)

all: test

test:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/binary_tree" \
		--workdir="/usr/src/binary_tree" \
		gcc:8.3 make docker-test

compare:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/binary_tree" \
		--workdir="/usr/src/binary_tree" \
		gcc:8.3 make docker-compare

docker-test:
	gcc -Wall -o /test binary_tree.h binary_tree.c test.h test.c && /test

docker-compare:
	gcc -Wall -o /test binary_tree.h binary_tree.c compare.c && /test

test.out: binary_tree.h binary_tree.c test.h test.c
	gcc -Wall -o $@ binary_tree.h binary_tree.c test.h test.c

clean:
	rm test.out
