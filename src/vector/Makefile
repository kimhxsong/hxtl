CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include -I .
LIBS = -L $(shell brew --prefix googletest)/lib -lgtest_main -lgtest -pthread  -lpthread -mmacosx-version-min=12.0

all: vector clean

vector:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) vector_unittest.cpp -o vector_unittest
	@./vector_unittest

clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: all vector clean