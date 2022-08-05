#include <iostream>
#include <limits>
#include <typeinfo>

#include "type_traits.hpp"

int main() {
  std::cout << std::boolalpha;

  ft::integral_constant<int, 42> forty_two;

  std::cout << forty_two.value << '\n';
  std::cout << forty_two << '\n';
  std::cout << typeid(ft::integral_constant<int, 42>::type).name() << '\n';

  ft::integral_constant<bool, true> b_true;

  std::cout << b_true.value << '\n';
  std::cout << b_true << '\n';
  std::cout << typeid(ft::integral_constant<bool, true>::type).name() << '\n';
}