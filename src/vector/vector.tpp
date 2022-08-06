#ifndef VECTOR_TPP_
#define VECTOR_TPP_

#ifndef VECTOR_HPP_
# error  vector.tpp:
#endif  // VECTOR_HPP_

#include "vector.hpp"

#include <memory>
#include <limits>
#include <exception>

#include "../algorithm/algorithm.hpp"

namespace ft {

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
 return (lhs.size() < rhs.size()) || ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  return !(lhs > rhs);
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  return rhs < lhs;
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class T, class Alloc>
void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs) {
  return lhs.swap(rhs);
}

template<typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
 : alloc_(alloc),
   elem_(0),
   space_(0),
   size_(0) {
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n,
                         const value_type& val,
                         const allocator_type& alloc)
  : alloc_(alloc),
    elem_(alloc_.allocate(n)),
    space_(n),
    size_(n) {
  for (size_type i = 0; i < n; i++) {
    alloc_.construct(&elem_[i], val);
  }
}

template <typename T, typename Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
                         InputIterator last, const allocator_type& alloc)
  : alloc_(alloc),
    elem_(0),
    space_(0),
    size_(0) {
  assign(first, last);
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const vector& x)
  : alloc_(x.alloc_),
    elem_(alloc_.allocate(x.space_)),
    space_(x.space_),
    size_(x.size_) {
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
  this->clear();
  reserve(rhs.space_);
  space_ = rhs.space_;
  size_ = rhs.size_;
  for (size_type i = 0; i < size_; i++) {
    *(elem_ + i) = *(rhs.elem_ + i);
  }
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
  return reverse_iterator(elem_ + size_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const {
  return const_reverse_iterator(elem_ + size_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend() {
  return reverse_iterator(elem_);
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const {
  return const_reverse_iterator(elem_);
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
    throw std::out_of_range(__func__);
  }
  return elem_[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
  if (n >= size_) {
    throw std::out_of_range(__func__);
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
  reserve(n);
  for (size_type i = size_; i < n; i++) {
    elem_[i] = val;
  }
  size_ = n;
}

template<typename T, typename Alloc>
void vector<T, Alloc>::swap(vector& other) {
  pointer tmp_elem = other.elem_;
  size_type tmp_size = other.size_;
  size_type tmp_space = other.space_;
  other.elem_ = this->elem_;
  other.size_ = this->size_;
  other.space_ = this->space_;
  this->elem_ = tmp_elem;
  this->size_ = tmp_size;
  this->space_ = tmp_space;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::reserve(size_type n) {
  if (max_size() < n) {
    throw std::length_error("__func__");
  }
  if (n <= space_) {
    return;
  }
  pointer elem = alloc_.allocate(n);
  for (size_type i = 0; i < size_; i++) {
    alloc_.construct(&elem_[i], elem_[i]);
  }
  for (size_type i = 0; i < size_; i++) {
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
void vector<T, Alloc>::assign(typename enable_if<!is_integral<InputIterator>::value,
                                                 InputIterator>::type first,
                                                 InputIterator last) {
  clear();
  reserve(static_cast<size_t>(std::distance(first, last)));
  for (; first != last; first++) {
    this->push_back(*first);
  }
}

template <typename T, typename Alloc>
void vector<T, Alloc>::assign(size_type n, const value_type& val) {
  clear();
  reserve(n);
  for (size_type i = 0; i < n; i++) {
    this->push_back(val);
  }
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
  return at(0);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
  return at(0);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
  return at(size_ > 0 ? size_ - 1 : size_);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
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

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator
vector<T, Alloc>::insert(iterator position, const value_type& val) {
  insert(position, 1, val);
  return ++position;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::insert(iterator position,
                              size_type n,
                              const value_type& val) {
  difference_type pos = std::distance(this->begin(), position);
  size_type new_size = size_ + n;
  reserve(new_size);
  difference_type src = size_;
  difference_type dest = new_size;
  while (dest > size_ && src > pos) {
    alloc_.construct(&elem_[--dest], elem_[--src]);
  }
  while (dest > size_ && n > 0) {
    alloc_.construct(&elem_[--dest], val);
    n--;
  }
  for (size_type i = 0; i < n; i++) {
    elem_[pos + i] = val;
  }
  size_ = new_size;
}

template <typename T, typename Alloc>
template <class InputIterator>
void vector<T, Alloc>::insert(iterator position,
    typename enable_if<!is_integral<InputIterator>::value,
                       InputIterator>::type first, InputIterator last) {
  difference_type pos = std::distance(this->begin(), position);
  size_type n = std::distance(first, last);
  size_type new_size = size_ + n;
  reserve(new_size);
  difference_type src = size_;
  difference_type dest = new_size;
  while (dest > size_ && src > pos) {
    alloc_.construct(&elem_[--dest], elem_[--src]);
  }
  while (dest > size_ && first != last) {
    alloc_.construct(&elem_[--dest], *--last);
  }
  iterator it(&elem_[pos]);
  while (first != last) {
    *it++ = *first++;
  }
  size_ = new_size;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position) {
  difference_type pos = std::distance(begin(), position);
  size_type n = 1;
  while (pos + n < size_) {
    elem_[pos] = elem_[pos + n];
    pos++;
  }
  while (n > 0) {
    alloc_.destroy(&elem_[size_ - 1]);
    size_--;
    n--;
  }
  return position;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {
  difference_type pos = std::distance(begin(), first);
  size_type n = std::distance(first, last);
  while (pos + n < size_) {
    elem_[pos] = elem_[pos + n];
    pos++;
  }
  while (n > 0) {
    alloc_.destroy(&elem_[size_ - 1]);
    size_--;
    n--;
  }
  return last;
}

}; // namespace ft

#endif // VECTOR_TPP_
