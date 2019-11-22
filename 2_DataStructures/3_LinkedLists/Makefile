DIR = $(shell pwd)

all: test

test:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/linked_list" \
		--workdir="/usr/src/linked_list" \
		gcc:8.3 make docker-test

docker-test:
	gcc -Wall -o /test linked_list.h linked_list.c test.h test.c && /test

test.out: linked_list.h linked_list.c test.h test.c
	gcc -Wall -o $@ linked_list.h linked_list.c test.h test.c

clean:
	rm test.out
