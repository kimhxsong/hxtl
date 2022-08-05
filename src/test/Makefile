vector:
	c++ vector_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o vector_unittest

map:
	c++ map_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o map_unittest

pair:
	c++ pair_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o pair_unittest

clean:
	rm *_unittest;
	rm -rf *.dSYM;