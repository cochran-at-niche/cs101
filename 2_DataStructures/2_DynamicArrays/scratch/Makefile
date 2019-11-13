DIR = $(shell pwd)

all: docker

# Local targets

main: main.c
	gcc -Wall -o $@ main.c

run: main
	./main

clean:
	rm main

# Docker targets

docker-main: main.c
	gcc -Wall -o /main main.c

docker-run: docker-main
	/main

docker:
	docker run --rm -it \
		--volume="$(DIR):/usr/src/scratch" \
		--workdir="/usr/src/scratch" \
		gcc:8.3 make docker-run
