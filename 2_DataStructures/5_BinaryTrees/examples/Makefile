DIR = $(shell pwd)

all: docker

# Local targets

search: search.c
	gcc -Wall -o $@ binary_tree.c search.c

run: search
	./search

clean:
	rm search

# Docker targets

docker-search: search.c
	gcc -Wall -o /search binary_tree.c search.c

docker-run: docker-search
	/search

docker:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/examples" \
		--workdir="/usr/src/examples" \
		gcc:8.3 make docker-run
