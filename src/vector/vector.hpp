#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cstddef>
#include <memory>  // allocator

#include "../iterator/iterator.hpp"
#include "../type_traits/type_traits.hpp"
#include "vector_iterator.hpp"

namespace ft {

template<typename T, typename Alloc> class vector;

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs);

template<typename T, typename Alloc = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef typename std::allocator<value_type> allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename ft::vector_iterator<pointer> iterator;
  typedef typename ft::vector_iterator<const_pointer> const_iterator;
  typedef typename ft::reverse_iterator<iterator> reverse_iterator;
  typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  explicit vector(const allocator_type& alloc = allocator_type());
  explicit vector(size_type n, const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type());
  template <class InputIterator>
  vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
         InputIterator last, const allocator_type& alloc = allocator_type());
  vector(const vector& x);
  ~vector();

  vector& operator=(const vector<T, Alloc>& rhs);
  template <class InputIterator>
  void assign(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
               InputIterator last);  
  void assign(size_type n, const value_type& val);
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
  iterator insert (iterator position, const value_type& val);
  void insert (iterator position, size_type n, const value_type& val);
  template <class InputIterator>
  void insert(iterator position,
      typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
      InputIterator last);
  iterator erase (iterator position);
  iterator erase (iterator first, iterator last);
  void push_back(const value_type& val);
  void pop_back();
  void resize(size_type n, value_type val = value_type());
  void swap(vector& other);

 private:
  allocator_type alloc_;
  pointer elem_;
  unsigned int space_;
  unsigned int size_;
};

}  // namespace ft

#include "vector.tpp"

#endif  // VECTOR_HPP_
