#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

#include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename iterator_traits<Iterator>::value_type value_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  typedef typename iterator_traits<Iterator>::reference reference;

  friend bool operator==(const reverse_iterator<Iterator>& lhs,
                          const reverse_iterator<Iterator>& rhs);

  friend bool operator!=(const reverse_iterator<Iterator>& lhs,
                          const reverse_iterator<Iterator>& rhs);

  friend bool operator<(const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs);

  friend bool operator<=(const reverse_iterator<Iterator>& lhs,
                          const reverse_iterator<Iterator>& rhs);

  friend bool operator>(const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs);

  friend bool operator>=(const reverse_iterator<Iterator>& lhs,
                          const reverse_iterator<Iterator>& rhs);

  friend typename reverse_iterator<Iterator>::difference_type operator-(
      const reverse_iterator<Iterator>& lhs,
      const reverse_iterator<Iterator>& rhs);

  friend reverse_iterator<Iterator> operator+(
      typename reverse_iterator<Iterator>::difference_type n,
      const reverse_iterator<Iterator>& rev_it);

  reverse_iterator();
  explicit reverse_iterator(iterator_type x);
  reverse_iterator(const reverse_iterator<Iterator>& other);

  iterator_type base() const;

  reference operator*() const;

  reverse_iterator& operator=(const reverse_iterator<Iterator>& other);

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

 protected:
  iterator_type current;
};

}  // namespace ft

#include "reverse_iterator.tpp"

#endif  // REVERSE_ITERATOR_HPP_
