CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include 
LIBS = -L $(shell brew --prefix googletest)/lib  -lgtest

all: is_integral enable_if clean

is_integral:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __is_integral_unittest.cpp -o __is_integral_unittest
	@./__is_integral_unittest

enable_if:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __enable_if_unittest.cpp -o __enable_if_unittest
	@./__enable_if_unittest

clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: all is_integral enable_if clean
