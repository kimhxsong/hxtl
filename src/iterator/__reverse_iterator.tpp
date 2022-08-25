#ifndef REVERSE_ITERATOR_TPP_
#define REVERSE_ITERATOR_TPP_

#ifndef REVERSE_ITERATOR_HPP_
#error __FILE__ should only be included from __reverse_iterator.hpp.
#endif  // REVERSE_ITERATOR_HPP_

#include "__reverse_iterator.hpp"

namespace ft {

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

#endif  // REVERSE_ITERATOR_TPP_
