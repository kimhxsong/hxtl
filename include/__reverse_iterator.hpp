#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

#include "__iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator;

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);

template <class Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                     const reverse_iterator<Iterator>& rev_it);

// Template paramters: Iterator
// A bidirectional iterator type. Or a random-access iterator, if an operator
// that requires such a category of iterators is used.
template <class Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename ft::iterator_traits<Iterator>::value_type value_type;
  typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
  typedef typename ft::iterator_traits<Iterator>::pointer pointer;
  typedef typename ft::iterator_traits<Iterator>::reference reference;

  reverse_iterator();                           // default (1)
  explicit reverse_iterator(iterator_type it);  // initialization (2)
  template <class Iter>
  reverse_iterator(const reverse_iterator<Iter>& rev_it);  // copy (3)

  iterator_type base() const;

  reference operator*() const;
  pointer operator->() const;

  reverse_iterator& operator++();
  reverse_iterator operator++(int);
  reverse_iterator& operator--();
  reverse_iterator operator--(int);
  reverse_iterator operator+(difference_type n) const;
  reverse_iterator& operator+=(difference_type n);
  reverse_iterator operator-(difference_type n) const;
  reverse_iterator& operator-=(difference_type n);
  reference operator[](difference_type n) const;

 protected:
  iterator_type current;
};

// Non-member function overloads
template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                     const reverse_iterator<Iterator>& rev_it) {
  return reverse_iterator<Iterator>(rev_it.base() - n);
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
  return rhs.base() - lhs.base();
}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator() : current() {}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : current(it) {}

template <class Iterator>
template <class Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it)
    : current(rev_it.base()) {}

template <class Iterator>
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const {
  return current;
};

template <class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const {
  iterator_type tmp = current;
  return *(--tmp);
}

template <class Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const {
  iterator_type tmp = current;
  return &(*(--tmp));
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++() {
  --current;
  return *this;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int) {
  reverse_iterator<Iterator> tmp(*this);
  --current;
  return tmp;
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--() {
  ++current;
  return *this;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int) {
  reverse_iterator<Iterator> tmp(*this);
  ++current;
  return tmp;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const {
  return reverse_iterator(current - n);
}

template <class Iterator>
ft::reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=(difference_type n) {
  current -= n;
  return *this;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const {
  return reverse_iterator(current + n);
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=(difference_type n) {
  current += n;
  return *this;
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](
    difference_type n) const {
  return *(*this + n);
}

}  // namespace ft

#endif  // REVERSE_ITERATOR_HPP_
