CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include -I .
LIBS = -L $(shell brew --prefix googletest)/lib -lgtest_main -lgtest -pthread  -lpthread -mmacosx-version-min=12.0

all: hx_tree clean

hx_tree:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) hx_tree_unittest.cpp -o hx_tree_unittest
	./hx_tree_unittest

clean:
	rm -f *_unittest;
	rm -rf *.dSYM;

.PHONY: all hx_tree clean
