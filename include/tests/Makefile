CXX = c++
CXXFLAGS = -std=c++11 -g
INCLUDES = -I $(shell brew --prefix googletest)/include -I ..
LIBS = -L $(shell brew --prefix googletest)/lib -lgtest_main -lgtest -pthread  -lpthread -mmacosx-version-min=12.0

.PHONY: all
all: vector map stack clean

.PHONY: vector
vector:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) vector_unittest.cpp -o vector_unittest
	@./vector_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: map
map:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) map_unittest.cpp -o map_unittest
	@./map_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: stack
stack:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) stack_unittest.cpp -o stack_unittest
	@./stack_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: iterator_traits
iterator_traits:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __iterator_traits_unittest.cpp -o __iterator_traits_unittest
	@./__iterator_traits_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;


.PHONY: reverse_iterator
reverse_iterator:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __reverse_iterator_unittest.cpp -o __reverse_iterator_unittest
	@./__reverse_iterator_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: is_integral
is_integral:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __is_integral_unittest.cpp -o __is_integral_unittest
	@./__is_integral_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: enable_if
enable_if:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __enable_if_unittest.cpp -o __enable_if_unittest
	@./__enable_if_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: pair
pair:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __pair_unittest.cpp -o __pair_unittest
	@./__pair_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: equal
equal:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __equal_unittest.cpp -o __equal_unittest
	@./__equal_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: lexi
lexi:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) __lexicographical_compare_unittest.cpp -o __lexicographical_compare_unittest
	@./__lexicographical_compare_unittest
	@rm -f *_unittest;
	@rm -rf *.dSYM;

.PHONY: clean
clean:
	@rm -f *_unittest;
	@rm -rf *.dSYM;