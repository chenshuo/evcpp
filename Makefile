CXXFLAGS=-O0 -g -Wall -Wextra -Werror
HEADERS=evcpp.h eventloop.h

all: test

test: test.cc $(HEADERS)
	g++ $(CXXFLAGS) -o $@ $<

clean:
	rm test

.PHONY: all clean

