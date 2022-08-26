#ifndef __INTEGRAL_CONSTANTS_HPP_
#define __INTEGRAL_CONSTANTS_HPP_

namespace ft {

template <class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant type;
  operator value_type() const throw() { return value; }  // conversion operator
};

}  // namespace ft

// Possible implementation
// From https://en.cppreference.com/w/cpp/types/integral_constant
// template<class T, T v>
// struct integral_constant {
//     static constexpr T value = v;
//     using value_type = T;
//     using type = integral_constant; // using injected-class-name
//     constexpr operator value_type() const noexcept { return value; }
//     constexpr value_type operator()() const noexcept { return value; } // since c++14
// };

#endif  // __INTEGRAL_CONSTANTS_HPP_
