DIR = $(shell pwd)

all: test

test:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/dynamic_array" \
		--workdir="/usr/src/dynamic_array" \
		gcc:8.3 make docker-test

compare:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/dynamic_array" \
		--workdir="/usr/src/dynamic_array" \
		gcc:8.3 make docker-compare

docker-test:
	gcc -Wall -o /test dynamic_array.h dynamic_array.c test.h test.c && /test

docker-compare:
	gcc -Wall -o /test dynamic_array.h dynamic_array.c compare.c && /test

test.out: dynamic_array.h dynamic_array.c test.h test.c
	gcc -Wall -o $@ dynamic_array.h dynamic_array.c test.h test.c

clean:
	rm test.out
