.DEFAULT_GOAL := build
.PHONY        := build clean

msg_info_help := "Commands: \
				 \n  build -> build executable \
				 \n  clean -> remove build artifact \
				 \n  help  -> output this message \
				 \n  run   -> run executable \
				 \n  test  -> run test"

build:
	clang -o bin/urlencode src/urlencoder.c

clean:
	rm bin/urlencode

help:
	@echo $(msg_info_help)

run:
	./bin/urlencode

test:
	./bin/test.sh
