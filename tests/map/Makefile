CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include -I .
LIBS = -L $(shell brew --prefix googletest)/lib -lgtest_main -lgtest -pthread  -lpthread -mmacosx-version-min=12.0


all: map clean

map:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) map_unittest.cpp -o map_unittest
	./map_unittest

clean:
	rm -f *_unittest;
	rm -rf *.dSYM;

.PHONY: all __tree clean
