#include "vector.hpp"

#include <iostream>
#include <memory>
#include <limits>
#include <exception>


vector::vector(const allocator_type& alloc)
 : alloc_(alloc),
   elem_(0),
   space_(0),
   size_(0) {
  std::cout << __func__ << std::endl;
}

vector::vector(size_type n, \
               const value_type& val, \
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

vector::vector(const vector& x)
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

vector::~vector() {
  if (elem_ != 0) { 
    for (size_type i = 0; i < size_; i++) {
      alloc_.destroy(&elem_[i]);
    }
    alloc_.deallocate(elem_, space_);
  }
}

vector& vector::operator=(const vector& rhs) {
  return *this;
}

vector::reference vector::operator[](vector::size_type n) {
  return elem_[n];
}

vector::const_reference vector::operator[](vector::size_type n) const {
  return elem_[n];
}

vector::reference vector::at(vector::size_type n) {
  if (n >= size_) {
    throw std::out_of_range("__func__");
  }
  return elem_[n];
}

vector::const_reference vector::at(vector::size_type n) const {
  if (n >= size_) {
    throw std::out_of_range("__func__");
  }
  return elem_[n];
}

vector::size_type vector::max_size() const {
  return std::numeric_limits<vector::size_type>::max() / sizeof(vector::value_type);
}

vector::size_type vector::size() const {
  return size_;
}

vector::size_type vector::capacity() const {
  return space_;
}

bool  vector::empty() const {
  return size_ == 0;
}

void vector::resize(vector::size_type n, vector::value_type val) {
  if (n == space_ && n == size_) { return; }
  vector::pointer elem = alloc_.allocate(n);
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

void vector::reserve(vector::size_type n) {
  if (n <= space_) { return; }
  vector::pointer elem = alloc_.allocate(n);
  for (size_type i = 0; i < size_; i++) {
    alloc_.construct(&elem[i], elem_[i]);
    alloc_.destroy(&elem_[i]);
  }
  alloc_.deallocate(elem_, space_);
  elem_ = elem;
  space_ = n;
}

// template <class InputIterator>
// void assign (InputIterator first, InputIterator last);

void vector::clear() {
  for (size_type i = 0; i < size_; i++) {
    alloc_.destroy(&elem_[i]);
  }
  size_ = 0;
}

void vector::assign(vector::size_type n, const vector::value_type& val) {
  clear();
  reserve(n);
  for (size_type i = 0; i < n; i++) {
    alloc_.construct(&elem_[i], val);
  }
}

vector::reference vector::front(size_type n) {
  return at(0);
}

vector::const_reference vector::front(size_type n) const {
  return at(0);
}

vector::reference vector::back(size_type n) {
  return at(size_ > 0 ? size_ - 1 : size_);
}

vector::const_reference vector::back(size_type n) const {
  return at(size_ > 0 ? size_ - 1 : size_);
}

vector::allocator_type vector::get_allocator() const {
  return alloc_;
}

void  vector::push_back(const value_type& val) {
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

void  vector::pop_back() {
  alloc_.destroy(&elem_[size_ - 1]);
  size_--;
}

// void vector::insert(){

// }