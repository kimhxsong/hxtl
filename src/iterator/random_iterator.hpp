#ifndef RANDOM_ITERATOR_HPP_
#define RANDOM_ITERATOR_HPP_

#include <ostream>

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class random_iterator {
 public:
  typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
  typedef typename ft::iterator_traits<T*>::value_type value_type;
  typedef typename ft::iterator_traits<T*>::difference_type difference_type;
  typedef typename ft::iterator_traits<T*>::pointer pointer;
  typedef typename ft::iterator_traits<T*>::reference reference;

  random_iterator();
  random_iterator(pointer p);
  random_iterator(const random_iterator<T>& other);

  ~random_iterator();

  random_iterator& operator=(const random_iterator<T>& other);

  reference operator*() const;
  pointer operator->() const;

  random_iterator& operator++();
  random_iterator operator++(int);

  random_iterator& operator--();
  random_iterator operator--(int);

  bool operator==(const random_iterator& other);
  bool operator!=(const random_iterator& other);

  bool operator<(const random_iterator& other);
  bool operator>(const random_iterator& other);
  bool operator<=(const random_iterator& other);
  bool operator>=(const random_iterator& other);

  random_iterator operator+(difference_type n) const;
  random_iterator operator-(difference_type n) const;

  difference_type operator-(const random_iterator& other);

  random_iterator& operator+=(difference_type n);
  random_iterator& operator-=(difference_type n);

  reference operator[](difference_type n) const;

 private:
  pointer p_;
};

}  // namespace ft

template <class T>
std::ostream& operator<<(std::ostream& os, const ft::random_iterator<T>& it);

#include "random_iterator.tpp"

#endif  // RANDOME_ITERATOR_HPP_
