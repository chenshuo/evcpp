CXXFLAGS=$$(cat cxxflags)
HEADERS=$(wildcard *.h)

all: test

test: test.cc $(HEADERS) cxxflags
	g++ $(CXXFLAGS) -o $@ $< -levent_core

clean:
	rm test

.PHONY: all clean

