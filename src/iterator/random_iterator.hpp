#ifndef RANDOM_ITERATOR_HPP_
#define RANDOM_ITERATOR_HPP_

#include <ostream>

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class random_iterator
  : public std::iterator<std::random_access_iterator_tag, T> {
 public:
  typedef typename random_iterator<T>::iterator_category iterator_category;
  typedef typename random_iterator<T>::value_type value_type;
  typedef typename random_iterator<T>::difference_type difference_type;
  typedef typename random_iterator<T>::pointer pointer;
  typedef typename random_iterator<T>::reference reference;

  random_iterator();
  random_iterator(pointer p);
  random_iterator(const random_iterator<T>& other);

  ~random_iterator();

  random_iterator& operator=(const random_iterator<T>& other);

  reference operator*();
  pointer operator->();

  random_iterator& operator++();
  random_iterator operator++(int);

  random_iterator& operator--();
  random_iterator operator--(int);

  bool operator==(const random_iterator& other);
  bool operator!=(const random_iterator& other);

  bool operator<(const random_iterator& other);
  bool operator>(const random_iterator& other);
  bool operator<=(const random_iterator& other);
  bool operator>=(const random_iterator& other);

  random_iterator operator+(difference_type n) const;
  random_iterator operator-(difference_type n) const;

  difference_type operator-(const random_iterator& other);

  random_iterator& operator+=(difference_type n);
  random_iterator& operator-=(difference_type n);

  reference operator[](difference_type n);

 private:
  pointer it_;
};

template<class T>
std::ostream& operator<<(const std::ostream& os, const random_iterator<T>& it);

}  // namespace ft

#endif  // RANDOME_ITERATOR_HPP_
