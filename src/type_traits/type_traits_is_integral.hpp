#ifndef TYPE_TRAITS_IS_INTEGRAL_HPP_
#define TYPE_TRAITS_IS_INTEGRAL_HPP_

namespace ft {

template <typename T>
struct is_integral : ft::integral_constant<bool, false> {};

template <>
struct is_integral<int> : ft::integral_constant<bool, true> {};

}  // ft::

#endif  // TYPE_TRAITS_IS_INTEGRAL_HPP_
