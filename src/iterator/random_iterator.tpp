#ifndef RANDOM_ITERATOR_HPP_
#error
#endif  // RANDOM_ITERATOR_HPP_

#ifndef RANDOM_ITERATOR_TPP_
#define RANDOM_ITERATOR_TPP_

#include "random_iterator.hpp"
#include <iostream>

namespace ft {

template <class T>
random_iterator<T>::random_iterator()
  : p_(0) {}

template <class T>
random_iterator<T>::random_iterator(pointer p)
  : p_(p) {}

template <class T>
random_iterator<T>::random_iterator(const random_iterator<value_type*>& other)
  : p_(&*other) {}

template <class T>
random_iterator<T>::~random_iterator() {}

template <class T>
random_iterator<T>& random_iterator<T>::operator=(const random_iterator<value_type*>& other) {
  p_ = &*other;
  return *this;
}

template <class T>
typename random_iterator<T>::reference random_iterator<T>::operator*() const {
  return *p_;
}

template <class T>
typename random_iterator<T>::pointer random_iterator<T>::operator->() const {
  return p_;
}

template <class T>
random_iterator<T>& random_iterator<T>::operator++() {
  ++p_;
  return *this;
}

template <class T>
random_iterator<T> random_iterator<T>::operator++(int) {
  random_iterator<T> tmp(*this);
  p_++;
  return tmp;
}

template <class T>
random_iterator<T>& random_iterator<T>::operator--() {
  --p_;
  return *this;
}

template <class T>
random_iterator<T> random_iterator<T>::operator--(int) {
  random_iterator<T> tmp(*this);
  p_--;
  return tmp;
}

template <class T>
bool random_iterator<T>::operator==(const random_iterator<T>& other) {
  return p_ == &*other;
}

template <class T>
bool random_iterator<T>::operator!=(const random_iterator<T>& other) {
  return p_ != &*other;
}

template <class T>
bool random_iterator<T>::operator<(const random_iterator<T>& other) {
  return p_ < &*other;
}

template <class T>
bool random_iterator<T>::operator>(const random_iterator<T>& other) {
  return p_ > &*other;
}

template <class T>
bool random_iterator<T>::operator<=(const random_iterator<T>& other) {
  return p_ <= &*other;
}

template <class T>
bool random_iterator<T>::operator>=(const random_iterator<T>& other) {
  return p_ >= &*other;
}

template <class T>
random_iterator<T> random_iterator<T>::operator+(difference_type n) const {
  random_iterator<pointer> tmp(p_ + n);
  return tmp;
}

template <class T>
random_iterator<T> random_iterator<T>::operator-(difference_type n) const {
  random_iterator<pointer> tmp(p_ - n);
  return tmp;
}

template <class T>
typename random_iterator<T>::difference_type random_iterator<T>::operator-(const random_iterator& other) {
  return p_ - &*other;
}

template <class T>
random_iterator<T>& random_iterator<T>::operator+=(difference_type n) {
  p_ += n;
  return *this;
}

template <class T>
random_iterator<T>& random_iterator<T>::operator-=(difference_type n) {
  p_ -= n;
  return *this;
}

template <class T>
typename random_iterator<T>::reference random_iterator<T>::operator[](difference_type n) const {
  return *(p_ + n);
}

}  // namespace ft

template <class T>
ft::random_iterator<T> operator+(int n, const ft::random_iterator<T>& it) {
  return it + n;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const ft::random_iterator<T>& it) {
  os << *it;
  return os;
}

#endif  // RANDOM_ITERATOR_TPP_
