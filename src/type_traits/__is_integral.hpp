#ifndef __IS_INTEGRAL_HPP_
#define __IS_INTEGRAL_HPP_

#include "__integral_constant.hpp"

namespace ft {
typedef ft::integral_constant<bool, true> true_type;
typedef ft::integral_constant<bool, false> false_type;

// struct true_type {
//   typedef bool value_type;
//   typedef true_type type;
//   static const value_type value = true;
//   operator value_type() { return value; }
// };

// struct false_type {
//   typedef bool value_type;
//   typedef false_type type;
//   static const value_type value = false;
//   operator value_type() { return value; }
// };

template <class T> struct is_integral : public false_type {};
template <class T> struct is_integral<const T> : public is_integral<T> {};
template <class T> struct is_integral<volatile const T> : public is_integral<T> {};
template <class T> struct is_integral<volatile T> : public is_integral<T> {};

template<> struct is_integral<unsigned char> : public true_type {};
template<> struct is_integral<unsigned short> : public true_type {};
template<> struct is_integral<unsigned int> : public true_type {};
template<> struct is_integral<unsigned long> : public true_type {};

template<> struct is_integral<signed char> : public true_type {};
template<> struct is_integral<short> : public true_type {};
template<> struct is_integral<int> : public true_type {};
template<> struct is_integral<long> : public true_type {};

template<> struct is_integral<char> : public true_type {};
template<> struct is_integral<bool> : public true_type {};

} // namespace ft

#endif  // __IS_INTEGRAL_HPP_
