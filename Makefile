CXXFLAGS=-O0 -g -Wall -Wextra -Werror

all: test

test: test.cc

clean:
	rm test

.PHONY: all clean

