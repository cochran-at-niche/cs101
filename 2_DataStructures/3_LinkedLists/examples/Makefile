DIR = $(shell pwd)

all: docker

# Local targets

singly_linked: singly_linked.c
	gcc -Wall -o $@ singly_linked.c

run: singly_linked
	./singly_linked

clean:
	rm singly_linked

# Docker targets

docker-singly_linked: singly_linked.c
	gcc -Wall -o /singly_linked singly_linked.c

docker-run: docker-singly_linked
	/singly_linked

docker:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/examples" \
		--workdir="/usr/src/examples" \
		gcc:8.3 make docker-run
