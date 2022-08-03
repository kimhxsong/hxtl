.PHONY: tree
tree:
	c++ tree_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o tree_unittest;
	./tree_unittest

.PHONY: map
map:
	c++ map_unittest.cpp -g -std=c++11 -I $(shell brew --prefix googletest)/include -L $(shell brew --prefix googletest)/lib -lgtest -o map_unittest
