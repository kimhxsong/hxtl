#ifndef VECTOR_ITERATOR_HPP_
#error
#endif  // VECTOR_ITERATOR_HPP_

#ifndef VECTOR_ITERATOR_TPP_
#define VECTOR_ITERATOR_TPP_

#include "vector_iterator.hpp"
#include <iostream>

namespace ft {

template <class T>
vector_iterator<T>::vector_iterator()
  : p_(0) {}

template <class T>
vector_iterator<T>::vector_iterator(pointer p)
  : p_(p) {}

template <class T>
vector_iterator<T>::vector_iterator(const vector_iterator<value_type*>& other)
  : p_(&*other) {}

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
bool vector_iterator<T>::operator==(const vector_iterator<T>& other) {
  return p_ == &*other;
}

template <class T>
bool vector_iterator<T>::operator!=(const vector_iterator<T>& other) {
  return p_ != &*other;
}

template <class T>
bool vector_iterator<T>::operator<(const vector_iterator<T>& other) {
  return p_ < &*other;
}

template <class T>
bool vector_iterator<T>::operator>(const vector_iterator<T>& other) {
  return p_ > &*other;
}

template <class T>
bool vector_iterator<T>::operator<=(const vector_iterator<T>& other) {
  return p_ <= &*other;
}

template <class T>
bool vector_iterator<T>::operator>=(const vector_iterator<T>& other) {
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
typename vector_iterator<T>::difference_type vector_iterator<T>::operator-(const vector_iterator& other) {
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
typename vector_iterator<T>::reference vector_iterator<T>::operator[](difference_type n) const {
  return *(p_ + n);
}

}  // namespace ft

template <class T>
ft::vector_iterator<T> operator+(int n, const ft::vector_iterator<T>& it) {
  return it + n;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const ft::vector_iterator<T>& it) {
  os << *it;
  return os;
}

#endif  // VECTOR_ITERATOR_TPP_
