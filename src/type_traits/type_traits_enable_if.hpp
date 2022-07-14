#ifndef TYPE_TRAITS_ENABLE_IF_HPP
#define TYPE_TRAITS_ENABLE_IF_HPP

namespace ft {

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

}  // ft::

#endif  // TYPE_TRAITS_ENABLE_IF_HPP
