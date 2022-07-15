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
iterator_type reverse_iterator<Iterator>::base() const {
  return current;
};

template<class Iterator>
reference reverse_iterator<Iterator>::operator*() const {
  return *current;
}

template<class Iterator>
pointer reverse_iterator<Iterator>::operator->() const {
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
reference reverse_iterator<Iterator>::operator[](difference_type n) const {
  return *(current + n);
}

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.current == rhs.current;
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.current != rhs.current;
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.current < rhs.current;
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.current <= rhs.current;
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.current > rhs.current;
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs) {
  return lhs.current >= rhs.current;
}

template <class Iterator>
reverse_iterator<Iterator> operator+(difference_type n,
                                     const reverse_iterator<Iterator>& rev_it) {
  return rev_it - n;
}

template <class Iterator>
difference_type operator-(const reverse_iterator<Iterator>& lhs,
                          const reverse_iterator<Iterator>& rhs) {
  return rhs - lhs;
}

}  // namespace ft

#endif  // REVERSE_ITERATOR_TPP_