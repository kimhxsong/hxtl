#include <iostream>
#include <limits>
#include <typeinfo>

#include "type_traits.hpp"

struct A {
  typedef int type;
};

struct B {
  typedef unsigned int type;
};

int main() {
  std::cout << std::boolalpha;

  std::cout << ft::is_integral<A::type>::value << '\n';
  std::cout << ft::is_integral<B::type>::value << '\n';
}
