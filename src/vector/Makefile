CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include 
LIBS = -L $(shell brew --prefix googletest)/lib  -lgtest

all: vector clean

vector:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) vector_unittest.cpp -o vector_unittest
	@./vector_unittest

clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: all vector clean