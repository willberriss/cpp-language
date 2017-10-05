
CXXFLAGS = -std=c++11 -pedantic -Wall -Werror -pthread
default: build
clean:
	rm -f threads

build: threads thread-race thread-function-address

build-threads: threads
build-thread-race: thread-race
build-thread-function-address: thread-function-address

run-threads: build-threads
	./threads

