
# c++17 is called c++1z currently
# N.B. This is NOT working on gcc (Raspbian 4.9.2-10) 4.9.2 for some reason
# It's not a recognized option, but should be I thought.
CXXFLAGS = -std=c++1z -pedantic -Wall -Werror

default: build
clean:
	rm -f *~
	rm -f base-derived-virtual-destructor
	rm -f base-derived-virtual-method
	rm -f member-variable-initialisation-order
	rm -f proggy

build-base-derived-virtual-destructor: base-derived-virtual-destructor
build-base-derived-virtual-method: base-derived-virtual-method
build-member-variable-initialisation-order: member-variable-initialisation-order
build-proggy: proggy

run-base-derived-virtual-method: base-derived-virtual-method
	./base-derived-virtual-method


