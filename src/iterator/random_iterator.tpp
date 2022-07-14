#ifndef RANDOM_ITERATOR_HPP_
#error
#endif  // RANDOM_ITERATOR_HPP_

#ifndef RANDOM_ITERATOR_TPP_
#define RANDOM_ITERATOR_TPP_

#include "random_iterator.hpp"

namespace ft {

template<class T>
random_iterator<T>::random_iterator()
  : p_(0) {}

template<class T>
random_iterator<T>::random_iterator(random_iterator<T>::pointer p)
  : p_(p) {}

template<class T>
random_iterator<T>::random_iterator(const random_iterator<T>& other)
  : p_(other.p_) {}

template<class T>
random_iterator<T>::~random_iterator() {}

template<class T>
random_iterator<T>& random_iterator<T>::operator=(random_iterator<T>& other) {
  p_ = other.p_;
  return *this;
}

template<class T>
reference random_iterator<T>::operator*() const {
  return *p_;
}

template<class T>
pointer random_iterator<T>::operator->() const {
  return p_;
}

template<class T>
random_iterator<T>& random_iterator<T>::operator++() {
  ++p_;
  return *this;
}

template<class T>
random_iterator<T> random_iterator<T>::operator++(int) {
  random_iterator<T> tmp(*this);
  p_++;
  return tmp;
}

template<class T>
random_iterator<T>& random_iterator<T>::operator--() {
  --p_;
  return *this;
}

template<class T>
random_iterator<T> random_iterator<T>::operator--(int) {
  random_iterator<T> tmp(*this);
  p_--;
  return tmp;
}

template <class T>
bool random_iterator<T>::operator==(const random_iterator<T>& other) {
  return p_ == other.p_;
}

template <class T>
bool random_iterator<T>::operator!=(const random_iterator<T>& other) {
  return p_ != other.p_;
}

template <class T>
bool random_iterator<T>::operator<(const random_iterator<T>& other) {
  return p_ < other.p_;
}

template <class T>
bool random_iterator<T>::operator>(const random_iterator<T>& other) {
  return p_ > other.p_;
}

template <class T>
bool random_iterator<T>::operator<=(const random_iterator<T>& other) {
  return p_ <= other.p_;
}

template <class T>
bool random_iterator<T>::operator>=(const random_iterator<T>& other) {
  return p_ >= other.p_;
}

template class T>
random_iterator<T> random_iterator<T>::operator+(difference_type n) const {
  return p_ + n;
}

template <class T>
random_iterator<T> random_iterator<T>::operator-(difference_type n) const {
  return p_ - n;
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
reference random_iterator<T>::operator[](difference_type n) const {
  return *(p_ + n);
}

template<class T>
std::ostream& operator<<(const std::ostream& os, const random_iterator<T>& it) {
  os << *p_;
  return *os;
}

}  // namespace ft

#endif  // RANDOM_ITERATOR_TPP_
