CXXFLAGS=$$(cat cxxflags)
HEADERS=callback.h evcpp.h eventloop.h

all: test

test: test.cc $(HEADERS) cxxflags
	g++ $(CXXFLAGS) -o $@ $<

clean:
	rm test

.PHONY: all clean

