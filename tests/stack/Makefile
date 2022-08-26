stack:
	c++ stack_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o stack_unittest
	./stack_unittest

clean:
	rm *_unittest;
	rm -rf *.dSYM;