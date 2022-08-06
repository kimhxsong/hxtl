#ifndef VECTOR_ITERATOR_HPP_
#define VECTOR_ITERATOR_HPP_

#include <ostream>

#include "../iterator/iterator.hpp"

namespace ft {

template <class T>
class vector_iterator {
 public:
  typedef typename iterator_traits<T>::iterator_category iterator_category;
  typedef typename iterator_traits<T>::value_type value_type;
  typedef typename iterator_traits<T>::difference_type difference_type;
  typedef typename iterator_traits<T>::pointer pointer;
  typedef const pointer const_pointer;
  typedef typename iterator_traits<T>::reference reference;
  typedef const reference const_reference;

  vector_iterator();
  vector_iterator(pointer p);
  vector_iterator(const vector_iterator<value_type*>& other);

  ~vector_iterator();

  vector_iterator& operator=(const vector_iterator<value_type*>& other);

  reference operator*();
  const_reference operator*() const;
  pointer operator->();
  const_pointer operator->() const;

  vector_iterator& operator++();
  vector_iterator operator++(int);

  vector_iterator& operator--();
  vector_iterator operator--(int);

  bool operator==(const vector_iterator& other);
  bool operator!=(const vector_iterator& other);

  bool operator<(const vector_iterator& other);
  bool operator>(const vector_iterator& other);
  bool operator<=(const vector_iterator& other);
  bool operator>=(const vector_iterator& other);

  vector_iterator operator+(difference_type n) const;
  vector_iterator operator-(difference_type n) const;

  difference_type operator-(const vector_iterator& other);

  vector_iterator& operator+=(difference_type n);
  vector_iterator& operator-=(difference_type n);

  reference operator[](difference_type n) const;

 private:
  pointer p_;
};

template <class T>
vector_iterator<T> operator+(int n, const vector_iterator<T>& it);

template <class T>
std::ostream& operator<<(std::ostream& os, const vector_iterator<T>& it);

}  // namespace ft

#include "vector_iterator.tpp"

#endif  // VECTORE_ITERATOR_HPP_
