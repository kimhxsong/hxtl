#ifndef TREE_ITERATOR_HPP_
#error
#endif  // TREE_ITERATOR_HPP_

#ifndef TREE_ITERATOR_TPP_
#define TREE_ITERATOR_TPP_

#include "tree_iterator.hpp"
#include <__tree>

namespace ft {

template<class T>
tree_iterator<T>::tree_iterator()
  : ptr_(0) {}

template<class T>
tree_iterator<T>::tree_iterator(tree_iterator<T>::pointer ptr)
  : ptr_(ptr) {}

template<class T>
tree_iterator<T>::tree_iterator(const tree_iterator<T>& other)
  : ptr_(other.ptr_) {}

template<class T>
tree_iterator<T>::~tree_iterator() {}

template<class T>
tree_iterator<T>& tree_iterator<T>::operator=(tree_iterator<T>& other) {
  ptr_ = other.ptr_;
  return *this;
}

template<class T>
reference tree_iterator<T>::operator*() const {
  return *ptr_;
}

template<class T>
pointer tree_iterator<T>::operator->() const {
  return ptr_;
}

template<class T>
tree_iterator<T>& tree_iterator<T>::operator++() {
  ++ptr_;
  return *this;
}

template<class T>
tree_iterator<T> tree_iterator<T>::operator++(int) {
  tree_iterator<T> tmp(*this);
  ptr_++;
  return tmp;
}

template<class T>
tree_iterator<T>& tree_iterator<T>::operator--() {
  --ptr_;
  return *this;
}

template<class T>
tree_iterator<T> tree_iterator<T>::operator--(int) {
  tree_iterator<T> tmp(*this);
  ptr_--;
  return tmp;
}

template <class T>
bool tree_iterator<T>::operator==(const tree_iterator<T>& other) {
  return ptr_ == other.ptr_;
}

template <class T>
bool tree_iterator<T>::operator!=(const tree_iterator<T>& other) {
  return ptr_ != other.ptr_;
}

template<class T>
std::ostream& operator<<(const std::ostream& os, const tree_iterator<T>& it) {
  os << *ptr_;
  return *os;
}

}  // namespace ft

#endif  // TREE_ITERATOR_TPP_
