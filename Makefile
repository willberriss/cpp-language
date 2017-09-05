
CXXFLAGS = -std=c++98 -pedantic -Wall -Werror
#CXXFLAGS = -std=c++11 -pedantic -Wall -Werror
#CXXFLAGS = -std=c++14 -pedantic -Wall -Werror

default: build
clean:
	rm -f hello
	rm -f test
	rm -f rvalue-ref
	rm -f rvo

build: hello test rvalue-ref rvo

build-array: array
build-hello: hello
build-test: test
build-rvalue-ref: rvalue-ref
build-lvalue-and-rvalue: lvalue-and-rvalue
build-rvo: rvo
build-rule-of-five: rule-of-five
build-tuple: tuple
build-smart-pointers: smart-pointers
build-initialisation: initialisation
build-numbers-and-strings: numbers-and-strings
build-copy-constructors: copy-constructors
build-move-constructors: move-constructors
build-base-derived-virtual: base-derived-virtual

run-hello: build-hello
	./hello

run-test: build-test
	./test

run-rvalue-ref: build-rvalue-ref
	./rvalue-ref

run-rvo: build-rvo
	./rvo

