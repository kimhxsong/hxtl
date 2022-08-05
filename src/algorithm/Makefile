CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include 
LIBS = -L $(shell brew --prefix googletest)/lib  -lgtest

all: equal clean

equal:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __equal_unittest.cpp -o __equal_unittest
	@./__equal_unittest

lexi:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __lexicographical_compare_unittest.cpp -o __lexicographical_compare_unittest
	@./__lexicographical_compare_unittest

clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: all equal lexi clean