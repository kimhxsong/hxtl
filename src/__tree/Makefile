CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include -I .
LIBS = -L $(shell brew --prefix googletest)/lib  -lgtest -mmacosx-version-min=12.0


all: __tree clean

__tree:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) tree_unittest2.cpp -o tree_unittest
	./tree_unittest

clean:
	rm -f *_unittest;
	rm -rf *.dSYM;

.PHONY: all __tree clean
