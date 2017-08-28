
CXXFLAGS = -std=c++11 -pedantic -Wall -Werror -pthread
default: build
clean:
	rm -f threads

build: threads

build-threads: threads
build-thread-race: thread-race

run-threads: build-threads
	./threads

