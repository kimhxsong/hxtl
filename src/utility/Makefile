.PHONY: all
all: pair

.PHONY: pair
pair:
	c++ pair_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o pair_unittest

.PHONY: clean
clean:
	rm *_unittest;
	rm -rf *.dSYM;