CXXFLAGS=$$(cat cxxflags)
HEADERS=$(wildcard *.h)

all: test

test: test.cc $(HEADERS) cxxflags
	g++ $(CXXFLAGS) -o $@ $<

clean:
	rm test

.PHONY: all clean

