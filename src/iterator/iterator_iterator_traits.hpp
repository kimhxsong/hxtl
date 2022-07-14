#ifndef ITERATOR_TRAITS_HPP_
#define ITERATOR_TRAITS_HPP_

#include <cstddef>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag {};
struct bidirectional_iterator_tag {};
struct random_access_iterator_tag {};

template<class Iter>
struct iterator_traits {
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::value_type value_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*> {
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef random_access_iterator_tag iterator_category;
  // FROM STD::
  // typedef std::random_access_iterator_tag iterator_category;
};

template<class T>  // (removed in C++ 20)
struct iterator_traits<const T*> {
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef random_access_iterator_tag iterator_category;
  // FROM STD::
  // typedef std::random_access_iterator_tag iterator_category;
};

}  // namespace ft

#endif  // ITERATOR_TRAITS_HPP_