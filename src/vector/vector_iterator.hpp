#ifndef VECTOR_ITERATOR_HPP_
#define VECTOR_ITERATOR_HPP_

#include <ostream>

#include "../iterator/iterator.hpp"

namespace ft {

template <class T>
class vector_iterator {
 public:
  typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
  typedef typename ft::iterator_traits<T>::value_type value_type;
  typedef typename ft::iterator_traits<T>::difference_type difference_type;
  typedef typename ft::iterator_traits<T>::pointer pointer;
  typedef typename ft::iterator_traits<T>::reference reference;
  typedef const pointer const_pointer;
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

  bool operator==(const vector_iterator& other) const;
  bool operator!=(const vector_iterator& other) const;

  bool operator<(const vector_iterator& other) const;
  bool operator>(const vector_iterator& other) const;
  bool operator<=(const vector_iterator& other) const;
  bool operator>=(const vector_iterator& other) const;

  vector_iterator operator+(difference_type n) const;
  vector_iterator operator-(difference_type n) const;

  difference_type operator-(const vector_iterator& other) const;

  vector_iterator& operator+=(difference_type n);
  vector_iterator& operator-=(difference_type n);

  reference operator[](difference_type n);
  const_reference operator[](difference_type n) const;

 private:
  pointer p_;
};

template <class T>
vector_iterator<T>::vector_iterator() : p_(0) {}
template <class T>
vector_iterator<T>::vector_iterator(pointer p) : p_(p) {}
template <class T>
vector_iterator<T>::vector_iterator(const vector_iterator<value_type*>& other) : p_(&*other) {}

template <class T>
vector_iterator<T>::~vector_iterator() {}

template <class T>
vector_iterator<T>& vector_iterator<T>::operator=(const vector_iterator<value_type*>& other) {
  p_ = &*other;
  return *this;
}

template <class T>
typename vector_iterator<T>::reference vector_iterator<T>::operator*() {
  return *p_;
}
template <class T>
typename vector_iterator<T>::const_reference vector_iterator<T>::operator*() const {
  return *p_;
}
template <class T>
typename vector_iterator<T>::pointer vector_iterator<T>::operator->() {
  return p_;
}
template <class T>
typename vector_iterator<T>::const_pointer vector_iterator<T>::operator->() const {
  return p_;
}

template <class T>
vector_iterator<T>& vector_iterator<T>::operator++() {
  ++p_;
  return *this;
}
template <class T>
vector_iterator<T> vector_iterator<T>::operator++(int) {
  vector_iterator<T> tmp(*this);
  p_++;
  return tmp;
}
template <class T>
vector_iterator<T>& vector_iterator<T>::operator--() {
  --p_;
  return *this;
}
template <class T>
vector_iterator<T> vector_iterator<T>::operator--(int) {
  vector_iterator<T> tmp(*this);
  p_--;
  return tmp;
}

template <class T>
bool vector_iterator<T>::operator==(const vector_iterator<T>& other) const {
  return p_ == &*other;
}
template <class T>
bool vector_iterator<T>::operator!=(const vector_iterator<T>& other) const {
  return p_ != &*other;
}

template <class T>
bool vector_iterator<T>::operator<(const vector_iterator<T>& other) const {
  return p_ < &*other;
}
template <class T>
bool vector_iterator<T>::operator>(const vector_iterator<T>& other) const {
  return p_ > &*other;
}
template <class T>
bool vector_iterator<T>::operator<=(const vector_iterator<T>& other) const {
  return p_ <= &*other;
}
template <class T>
bool vector_iterator<T>::operator>=(const vector_iterator<T>& other) const {
  return p_ >= &*other;
}

template <class T>
vector_iterator<T> vector_iterator<T>::operator+(difference_type n) const {
  vector_iterator<pointer> tmp(p_ + n);
  return tmp;
}
template <class T>
vector_iterator<T> vector_iterator<T>::operator-(difference_type n) const {
  vector_iterator<pointer> tmp(p_ - n);
  return tmp;
}

template <class T>
typename vector_iterator<T>::difference_type vector_iterator<T>::operator-(
    const vector_iterator& other) const {
  return p_ - &*other;
}

template <class T>
vector_iterator<T>& vector_iterator<T>::operator+=(difference_type n) {
  p_ += n;
  return *this;
}
template <class T>
vector_iterator<T>& vector_iterator<T>::operator-=(difference_type n) {
  p_ -= n;
  return *this;
}

template <class T>
typename vector_iterator<T>::reference vector_iterator<T>::operator[](difference_type n) {
  return *(p_ + n);
}
template <class T>
typename vector_iterator<T>::const_reference vector_iterator<T>::operator[](
    difference_type n) const {
  return *(p_ + n);
}

template <class T>
vector_iterator<T> operator+(int n, const vector_iterator<T>& it) {
  return it + n;
}

// non-member functions
template <class T1, class T2>
typename ft::vector_iterator<T1>::difference_type operator-(const ft::vector_iterator<T1>& lhs,
                                                            const ft::vector_iterator<T2>& rhs) {
  return lhs - rhs;
}

template <class T1, class T2>
bool operator==(const ft::vector_iterator<T1>& lhs, const ft::vector_iterator<T2>& rhs) {
  return lhs == rhs;
}

template <class T1, class T2>
bool operator!=(const ft::vector_iterator<T1>& lhs, const ft::vector_iterator<T2>& rhs) {
  return lhs != rhs;
}

template <class T1, class T2>
bool operator<(const ft::vector_iterator<T1>& lhs, const ft::vector_iterator<T2>& rhs) {
  return lhs < rhs;
}

template <class T1, class T2>
bool operator<=(const ft::vector_iterator<T1>& lhs, const ft::vector_iterator<T2>& rhs) {
  return lhs <= rhs;
}

template <class T1, class T2>
bool operator>(const ft::vector_iterator<T1>& lhs, const ft::vector_iterator<T2>& rhs) {
  return lhs > rhs;
}

template <class T1, class T2>
bool operator>=(const ft::vector_iterator<T1>& lhs, const ft::vector_iterator<T2>& rhs) {
  return lhs >= rhs;
}

}  // namespace ft

#endif  // VECTORE_ITERATOR_HPP_
