CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include 
LIBS = -L $(shell brew --prefix googletest)/lib  -lgtest

all: iterator_traits reverse_iterator clean

iterator_traits:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __iterator_traits_unittest.cpp -o __iterator_traits_unittest
	@./__iterator_traits_unittest

reverse_iterator:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __reverse_iterator_unittest.cpp -o __reverse_iterator_unittest
	@./__reverse_iterator_unittest

clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: all iterator_traits reverse_iterator clean
