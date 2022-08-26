CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include 
LIBS = -L $(shell brew --prefix googletest)/lib  -lgtest

all: pair clean

pair:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __pair_unittest.cpp -o __pair_unittest
	@./__pair_unittest

clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: all pair clean
