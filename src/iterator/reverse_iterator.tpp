#ifndef REVERSE_ITERATOR_TPP_
#define REVERSE_ITERATOR_TPP_

#ifndef REVERSE_ITERATOR_HPP_
#error
#endif  // REVERSE_ITERATOR_HPP_

#include "reverse_iterator.hpp"

namespace ft {

template<class Iterator>
reverse_iterator<Iterator>::reverse_iterator()
  : current() {}

template<class Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type x)
  : current(x) {}

template<class Iterator>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iterator>& other)
  : current(other.current) {}

template<class Iterator>
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const {
  return current;
};

template<class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const {
  return *current;
}

template<class Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const {
  return current;
}

template<class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator=(
    const reverse_iterator<Iterator>& other) {
  current = other.current;
  return *this;
}

template<class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++() {
  --current;
  return *this;
}

template<class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--() {
  ++current;
  return *this;
}

template<class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int) {
    reverse_iterator<Iterator> tmp(*this);
  --current;
  return tmp;
}

template<class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int) {
    reverse_iterator<Iterator> tmp(*this);
  ++current;
  return tmp;
}

template<class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(
    difference_type n) const {
  return current - n;
}

template<class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(
    difference_type n) const {
  return current + n;
}

template<class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=(
    difference_type n) {
  current -= n;
  return *this;
}

template<class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=(
    difference_type n) {
  current += n;
  return *this;
}

template<class Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const {
  return *(current + n);
}

}  // namespace ft

template <class Iterator1, class Iterator2>
bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iterator>
ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
                                     const ft::reverse_iterator<Iterator>& rev_it) {
  return ft::reverse_iterator<Iterator>(rev_it.base() - n);
}

template <class Iterator1, class Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1>& lhs,
                          const ft::reverse_iterator<Iterator2>& rhs) {
  return rhs.base() - lhs.base();
}

#endif  // REVERSE_ITERATOR_TPP_