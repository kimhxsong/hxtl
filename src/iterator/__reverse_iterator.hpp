#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

#include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename ft::iterator_traits<Iterator>::value_type value_type;
  typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
  typedef typename ft::iterator_traits<Iterator>::pointer pointer;
  typedef typename ft::iterator_traits<Iterator>::reference reference;

  reverse_iterator();
  explicit reverse_iterator(iterator_type x);
  
  template <class Iter>
  reverse_iterator(const reverse_iterator<Iter>& other);

  iterator_type base() const;

  reference operator*() const;

  template <class Iter>
  reverse_iterator& operator=(const reverse_iterator<Iter>& other);

  reverse_iterator& operator++();
  reverse_iterator& operator--();

  reverse_iterator operator++(int);
  reverse_iterator operator--(int);

  reverse_iterator operator+(difference_type n) const;
  reverse_iterator operator-(difference_type n) const;

  reverse_iterator& operator+=(difference_type n);
  reverse_iterator& operator-=(difference_type n);

  pointer operator->() const;
  reference operator[](difference_type n) const;

  iterator_type current;
 protected:
};

}  // namespace ft

#include "reverse_iterator.tpp"

template <class Iterator1, class Iterator2>
bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
                  const ft::reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
               const ft::reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs);
template <class Iterator1, class Iterator2>
bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs);

template <class Iterator1, class Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type operator-(
    const ft::reverse_iterator<Iterator1>& lhs,
    const ft::reverse_iterator<Iterator2>& rhs);

template <class Iterator>
ft::reverse_iterator<Iterator> operator+(
  typename ft::reverse_iterator<Iterator>::difference_type n,
  const ft::reverse_iterator<Iterator>& rev_it);

#endif  // REVERSE_ITERATOR_HPP_
