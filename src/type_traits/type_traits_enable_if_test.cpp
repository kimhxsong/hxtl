#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <limits>

#include "type_traits_enable_if.hpp"

using ft::enable_if;

template<class T>
void do_something(unsigned int arg) {
  std::cout << typeid(arg).name() << std::endl;
}

template <class T>
void do_something(T arg) {
  std::cout << typeid(arg).name() << std::endl;
}

template<class T2>
void do_something2(unsigned int arg) {
  std::cout << typeid(arg).name() << std::endl;
}

template <class T2>
void do_something2(typename enable_if<std::is_class<T2>::value, T2>::value_type arg) {
  std::cout << typeid(arg).name() << std::endl;
}

template <class T3>
void do_something3(unsigned int arg) {
  std::cout << typeid(arg).name() << std::endl;
}

// SFINAE
template <class T3>
void do_something3(typename enable_if<std::is_integral<T3>::value, T3>::value_type arg) {
  std::cout << typeid(arg).name() << std::endl;
}

int main() {
  std::cout << "do_something\n";
  do_something<int>(42);
  do_something<int>(std::numeric_limits<int>::max());
  do_something<int>(static_cast<unsigned int>(0));
  do_something<int>(std::numeric_limits<unsigned int>::max());
  std::cout << std::endl;

  std::cout << "do_something2\n";
  do_something2<int>(42);
  do_something2<int>(std::numeric_limits<int>::max());
  do_something2<int>(static_cast<unsigned int>(0));
  do_something2<int>(std::numeric_limits<unsigned int>::max());
  std::cout << std::endl;

  // SFINAE
  std::cout << "do_something3\n";
  do_something3<int>(42);
  do_something3<int>(std::numeric_limits<int>::max());
  do_something3<int>(static_cast<unsigned int>(0));
  do_something3<int>(std::numeric_limits<unsigned int>::max());
  std::cout << std::endl;
}