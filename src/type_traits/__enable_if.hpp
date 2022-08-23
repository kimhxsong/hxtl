#ifndef __ENABLE_IF_HPP_
#define __ENABLE_IF_HPP_

namespace ft
{

template <bool B, class T = void> struct enable_if
{};

template <class T> struct enable_if<true, T>
{
  typedef T type;
};

}  // namespace ft

#endif  // __ENABLE_IF_HPP_
