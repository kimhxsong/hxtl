#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid

#include "iterator_iterator_traits.hpp"

int main() {
  typedef std::iterator_traits<int*> std_traits;
  if (typeid(std_traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "[std]:\tint* is a random-access iterator\n";

  typedef ft::iterator_traits<int*> ft_traits;
  if (typeid(ft_traits::iterator_category)==typeid(ft::random_access_iterator_tag))
    std::cout << "[ft]:\tint* is a random-access iterator\n";

  return 0;
}
