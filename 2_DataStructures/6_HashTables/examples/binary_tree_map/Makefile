DIR = $(shell pwd)

all: docker

# Local targets

main: main.c
	gcc -Wall -o $@ map.c main.c

run: main
	./main

clean:
	rm main

# Docker targets

docker-main: main.c
	gcc -Wall -o /main map.c main.c

docker-run: docker-main
	/main

docker:
	@docker run --rm -it \
		--volume="$(DIR):/usr/src/examples" \
		--workdir="/usr/src/examples" \
		gcc:8.3 make docker-run
