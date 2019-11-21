DIR = $(shell pwd)

all: test

test:
	docker run --rm -it \
		--volume="$(DIR):/src" \
		--workdir="/src" \
		golang:1.13 go test
