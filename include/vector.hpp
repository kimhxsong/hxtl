#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstddef>
#include <memory>

#include "__enable_if.hpp"
#include "__equal.hpp"
#include "__is_integral.hpp"
#include "__lexicographical_compare.hpp"
#include "__reverse_iterator.hpp"

namespace ft {

template <class T>
class vector_iterator {
 public:
  typedef T* iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
  typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference reference;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

 private:
  pointer p_;

 public:
  vector_iterator() : p_(0) {}

  template <class U>
  vector_iterator(const vector_iterator<U>& other) : p_(other.base()) {}

  ~vector_iterator() {}

  template <class U>
  vector_iterator& operator=(const vector_iterator<U>& i) {
    p_ = i.base();
    return *this;
  }

  explicit vector_iterator(pointer p) : p_(p) {}

  iterator_type base(void) const { return p_; }

  pointer operator->(void) const { return p_; }

  reference operator*(void) const { return *p_; }

  reference operator[](difference_type n) const { return *(p_ + n); }

  vector_iterator& operator++(void) {
    ++p_;
    return *this;
  }
  vector_iterator& operator--(void) {
    --p_;
    return *this;
  }
  vector_iterator operator++(int) {
    vector_iterator tmp(*this);
    ++p_;
    return tmp;
  }
  vector_iterator operator--(int) {
    vector_iterator tmp(*this);
    --p_;
    return tmp;
  }

  vector_iterator operator+(difference_type n) const { return vector_iterator(p_ + n); }

  vector_iterator operator-(difference_type n) const { return vector_iterator(p_ - n); }

  vector_iterator& operator+=(difference_type n) {
    p_ += n;
    return *this;
  }

  vector_iterator& operator-=(difference_type n) {
    p_ -= n;
    return *this;
  }
};

//
// Non Member Functions
//
template <class T>
vector_iterator<T> operator+(typename vector_iterator<T>::difference_type n,
                             const vector_iterator<T>& rhs) {
  return vector_iterator<T>(rhs.base() + n);
}

template <class T1, class T2>
typename vector_iterator<T1>::difference_type operator-(const vector_iterator<T1>& lhs,
                                                        const vector_iterator<T2>& rhs) {
  return lhs.base() - rhs.base();
}

template <class T1, class T2>
bool operator==(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class T1, class T2>
bool operator!=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return lhs.base() < rhs.base();
}

template <class T1, class T2>
bool operator<=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return !(lhs > rhs);
}

template <class T1, class T2>
bool operator>(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return !(lhs < rhs);
}

template <typename T, typename Alloc = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef typename std::allocator<value_type> allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;

  typedef ft::vector_iterator<value_type> iterator;
  typedef ft::vector_iterator<const value_type> const_iterator;
  typedef typename ft::reverse_iterator<iterator> reverse_iterator;
  typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

 public:
  explicit vector(const allocator_type& alloc = allocator_type());
  explicit vector(size_type n, const_reference val = value_type(),
                  const allocator_type& alloc = allocator_type());
  template <class InputIterator>
  vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
         InputIterator last, const allocator_type& alloc = allocator_type());
  vector(const vector& x);
  ~vector();

  vector& operator=(const vector& rhs);
  template <class InputIterator>
  void assign(
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
      InputIterator last);
  void assign(size_type n, const_reference val);
  allocator_type get_allocator() const;

  reference at(size_type n);
  const_reference at(size_type n) const;
  reference operator[](size_type n);
  const_reference operator[](size_type n) const;
  reference front(size_type n);
  const_reference front(size_type n) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type n);
  size_type capacity() const;

  void clear();
  iterator insert(iterator position, const_reference val);
  void insert(iterator position, size_type n, const_reference val);
  template <class InputIterator>
  void insert(
      iterator position,
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
      InputIterator last);
  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);
  void push_back(const_reference val);
  void pop_back();
  void resize(size_type n, value_type val = value_type());
  void swap(vector& other);

 private:
  allocator_type alloc_;
  pointer elem_;
  size_type space_;
  size_type size_;
};

template <class T, class Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
    : alloc_(alloc), elem_(0), space_(0), size_(0) {}

template <class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const_reference val, const allocator_type& alloc)
    : alloc_(alloc), elem_(alloc_.allocate(n)), space_(n), size_(n) {
  for (size_type i = 0; i < n; i++) {
    alloc_.construct(&elem_[i], val);
  }
}

template <class T, class Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(
    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
    InputIterator last, const allocator_type& alloc)
    : alloc_(alloc), elem_(0), space_(0), size_(0) {
  assign(first, last);
}

template <class T, class Alloc>
vector<T, Alloc>::vector(const vector& x)
    : alloc_(x.alloc_), elem_(alloc_.allocate(x.space_)), space_(x.space_), size_(x.size_) {
  if (space_ > 0) {
    for (size_type i = 0; i < size_; i++) {
      alloc_.construct(&elem_[i], x.elem_[i]);
    }
  }
}

template <class T, class Alloc>
vector<T, Alloc>::~vector() {
  if (elem_ != 0) {
    for (size_type i = 0; i < size_; i++) {
      alloc_.destroy(&elem_[i]);
    }
    alloc_.deallocate(elem_, space_);
  }
}

template <class T, class Alloc>
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

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() {
  return iterator(elem_);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const {
  return const_iterator(elem_);
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end() {
  return iterator(elem_ + size_);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const {
  return const_iterator(elem_ + size_);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin() {
  return reverse_iterator(this->end());
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const {
  return const_reverse_iterator(this->end());
}

template <class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend() {
  return reverse_iterator(this->begin());
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const {
  return const_reverse_iterator(this->begin());
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n) {
  return elem_[n];
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const {
  return elem_[n];
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
  if (n >= size_) {
    throw std::out_of_range(__func__);
  }
  return elem_[n];
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
  if (n >= size_) {
    throw std::out_of_range(__func__);
  }
  return elem_[n];
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
  return size_;
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
  return space_;
}

template <class T, class Alloc>
bool vector<T, Alloc>::empty() const {
  return size_ == 0;
}

template <class T, class Alloc>
void vector<T, Alloc>::resize(size_type n, value_type val) {
  reserve(n);
  for (size_type i = size_; i < n; i++) {
    elem_[i] = val;
  }
  size_ = n;
}

template <class T, class Alloc>
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

template <class T, class Alloc>
void vector<T, Alloc>::reserve(size_type n) {
  if (n > max_size()) {
    throw std::length_error(__func__);
  }

  if (n <= space_) {
    return;
  }

  pointer elem = alloc_.allocate(n);
  if (!ft::is_integral<value_type>::value) {
    for (size_type i = 0; i < size_; i++) {
      alloc_.construct(&elem[i], elem_[i]);
    }
    for (size_type i = 0; i < size_; i++) {
      alloc_.destroy(&elem_[i]);
    }
  } else {
    for (size_type i = 0; i < size_; i++) {
      elem[i] = elem_[i];
    }
  }

  alloc_.deallocate(elem_, space_);
  elem_ = elem;
  space_ = n;
}

template <class T, class Alloc>
void vector<T, Alloc>::clear() {
  for (size_type i = 0; i < size_; i++) {
    alloc_.destroy(&elem_[i]);
  }
  size_ = 0;
}

template <class T, class Alloc>
template <class InputIterator>
void vector<T, Alloc>::assign(
    typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
    InputIterator last) {
  clear();
  reserve(static_cast<size_t>(std::distance(first, last)));
  for (; first != last; first++) {
    this->push_back(*first);
  }
}

template <class T, class Alloc>
void vector<T, Alloc>::assign(size_type n, const_reference val) {
  clear();
  reserve(n);
  for (size_type i = 0; i < n; i++) {
    this->push_back(val);
  }
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
  return at(0);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
  return at(0);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
  return at(size_ > 0 ? size_ - 1 : size_);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
  return at(size_ > 0 ? size_ - 1 : size_);
}

template <class T, class Alloc>
typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const {
  return alloc_;
}

template <class T, class Alloc>
void vector<T, Alloc>::push_back(const_reference val) {
  if (space_ == size_) {
    int new_space = space_ < (max_size() / 2) ? (space_ << 1) : max_size();
    if (new_space == 0) {
      ++new_space;
    }

    reserve(new_space);
    space_ = new_space;
  }

  alloc_.construct(&elem_[size_], val);
  size_++;
}

template <class T, class Alloc>
void vector<T, Alloc>::pop_back() {
  if (size_ == 0) {
    return;
  }
  alloc_.destroy(&elem_[size_ - 1]);
  size_--;
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position,
                                                             const_reference val) {
  difference_type pos = std::distance(this->begin(), position);
  insert(position, 1, val);
  return begin() + pos;
}

template <class T, class Alloc>
void vector<T, Alloc>::insert(iterator position, size_type n, const_reference val) {
  difference_type pos = std::distance(this->begin(), position);
  size_type new_size = size_ + n;
  this->reserve(new_size);
  size_type src_idx = size_;
  size_type dest_idx = new_size;
  for (size_type i = this->size_ - pos; i > 0; i--) {
    alloc_.construct(&this->elem_[--dest_idx], this->elem_[--src_idx]);
  }

  if (n > this->size_ - pos) {
    for (size_type i = n - this->size_ + pos; i > 0; i--) {
      alloc_.construct(&elem_[--dest_idx], val);
    }
  }

  while (src_idx != static_cast<size_type>(pos)) {
    this->elem_[--dest_idx] = this->elem_[--src_idx];
  }

  while (n--) {
    this->elem_[pos + n] = val;
  }
  this->size_ = new_size;
}

template <class T, class Alloc>
template <class InputIterator>
void vector<T, Alloc>::insert(
    iterator position,
    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
    InputIterator last) {
  while (first != last) {
    position = this->insert(position, *first++);
    ++position;
  }
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position) {
  difference_type pos = std::distance(begin(), position);
  size_type n = 1;
  for (size_type idx = pos; idx < size_; idx++) {
    elem_[idx] = elem_[idx + n];
  }

  while (n > 0) {
    alloc_.destroy(&elem_[size_ - 1]);
    size_--;
    n--;
  }

  return begin() + pos;
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {
  difference_type pos = std::distance(begin(), first);
  size_type n = std::distance(first, last);
  for (size_type idx = pos; idx < size_; idx++) {
    elem_[idx] = elem_[idx + n];
  }

  while (n > 0) {
    alloc_.destroy(&elem_[size_ - 1]);
    size_--;
    n--;
  }

  return begin() + pos;
}

//
// Non Member Functions
//
template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
  return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
  return !(lhs > rhs);
}

template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
  return rhs < lhs;
}

template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
  return lhs.swap(rhs);
}

}  // namespace ft

#endif  // VECTOR_HPP_
