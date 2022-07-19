#ifndef VECTOR_HPP_
#error what?
#endif  // VECTOR_HPP_

#ifndef VECTOR_TPP_
#define VECTOR_TPP_

#include "../iterator/random_iterator.hpp"

#include <iostream>
#include <memory>
#include <limits>
#include <exception>

#include "vector.hpp"
#include <type_traits>

namespace ft {

template<typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
 : alloc_(alloc),
   elem_(0),
   space_(0),
   size_(0) {
  std::cout << __func__ << std::endl;
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n,
                         const value_type& val,
                         const allocator_type& alloc)
  : alloc_(alloc),
    elem_(alloc_.allocate(n)),
    space_(n),
    size_(n) {
  std::cout << __func__ << std::endl;
  if (space_ > 0) {
    for (size_type i = 0; i < size_; i++) {
      alloc_.construct(&elem_[i], val);
    }
  }
}

template <typename T, typename Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first,
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
      const allocator_type& alloc)
  : alloc_(alloc),
    elem_(0),
    space_(0),
    size_(0) {
  for (; first != last; first++) {
    this->push_back(*first);
  }
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const vector<T, Alloc>& x)
  : alloc_(x.alloc_),
    elem_(alloc_.allocate(x.space_)),
    space_(x.space_),
    size_(x.size_) {
  std::cout << __func__ << std::endl;
  if (space_ > 0) {
    for (size_type i = 0; i < size_; i++) {
      alloc_.construct(&elem_[i], x.elem_[i]);
    }
  }
}

template <typename T, typename Alloc>
vector<T, Alloc>::~vector() {
  if (elem_ != 0) { 
    for (size_type i = 0; i < size_; i++) {
      alloc_.destroy(&elem_[i]);
    }
    alloc_.deallocate(elem_, space_);
  }
}

template <typename T, typename Alloc>
vector<T, Alloc>& vector<T, Alloc>::operator=(const vector& rhs) {
  return *this;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() {
  return iterator(elem_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const {
  return const_iterator(elem_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end() {
  return iterator(elem_ + size_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const {
  return const_iterator(elem_ + size_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin() {
  return reverse_iterator(elem_ + size_ - 1);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const {
  return const_reverse_iterator(elem_ + size_ - 1);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend() {
  return reverse_iterator(elem_ - 1);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const {
  return const_reverse_iterator(elem_ - 1);
}


template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n) {
  return elem_[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const {
  return elem_[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
  if (n >= size_) {
    throw std::out_of_range("__func__");
  }
  return elem_[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
  if (n >= size_) {
    throw std::out_of_range("__func__");
  }
  return elem_[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
  return size_;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
  return space_;
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::empty() const {
  return size_ == 0;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::resize(size_type n, value_type val) {
  if (n == space_ && n == size_) {
    return;
  }
  pointer elem = alloc_.allocate(n);
  for (size_type i = n; i < size_; i++) {
    alloc_.destroy(&elem_[i]);
  }
  for (int i = 0; i < n; i++) {
    alloc_.construct(&elem[i], elem_[i]);
    alloc_.destroy(&elem_[i]);
  }
  for (int i = size_; i < n; i++) {
    alloc_.construct(&elem[i], val);
  }
  alloc_.deallocate(elem_, space_);
  elem_ = elem;
  space_ = n;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::reserve(size_type n) {
  if (n <= space_) {
    return;
  }
  pointer elem = alloc_.allocate(n);
  for (size_type i = 0; i < size_; i++) {
    alloc_.construct(&elem[i], elem_[i]);
    alloc_.destroy(&elem_[i]);
  }
  alloc_.deallocate(elem_, space_);
  elem_ = elem;
  space_ = n;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::clear() {
  for (size_type i = 0; i < size_; i++) {
    alloc_.destroy(&elem_[i]);
  }
  size_ = 0;
}

template <typename T, typename Alloc>
template <class InputIterator>
void vector<T, Alloc>::assign(InputIterator first, InputIterator last) {
  clear();
  for (; first != last; first++) {
    this->push_back(*first);
  }
}

template <typename T, typename Alloc>
void vector<T, Alloc>::assign(size_type n, const value_type& val) {
  clear();
  reserve(n);
  for (size_type i = 0; i < n; i++) {
    alloc_.construct(&elem_[i], val);
  }
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front(size_type n) {
  return at(0);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front(size_type n) const {
  return at(0);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back(size_type n) {
  return at(size_ > 0 ? size_ - 1 : size_);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back(size_type n) const {
  return at(size_ > 0 ? size_ - 1 : size_);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const {
  return alloc_;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(const value_type& val) {
  if (space_ == size_) {
    int new_space = space_ << 1;
    if (new_space == 0) {
      new_space++;
    }
    reserve(new_space);
    space_ = new_space;
  }
  alloc_.construct(&elem_[size_], val);
  size_++;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::pop_back() {
  alloc_.destroy(&elem_[size_ - 1]);
  size_--;
}

// template <typename T, typename Alloc>
// void vector<T, Alloc>::insert(){

}

#endif // VECTOR_TPP_