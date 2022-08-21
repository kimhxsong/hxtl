#ifndef TREE_ITERATOR_HPP_
#define TREE_ITERATOR_HPP_

#include <cstddef>
#include <iterator>
#include <ostream>

#include "__tree.hpp"

namespace ft {

// template class __tree_iterator<class, class, class> is Bidirectional
// iterators
template <typename T, typename NodePtr> class __tree_iterator {
public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef T *pointer;
  typedef T &reference;
  typedef const T *const_pointer;
  typedef const T &const_reference;
  // typedef NodePtr node_pointer;

  // Property:
  // Is default-constructible, copy-constructible, copy-assignable and
  // destructible
  __tree_iterator();
  __tree_iterator(const __tree_iterator &other);
  __tree_iterator(const __tree_iterator < value_type,
                  ft::__tree<value_type>::node_pointer &other);
  __tree_iterator &operator=(const __tree_iterator &other);
  ~__tree_iterator();

  // Property:
  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  reference operator*();
  const_reference operator*() const;
  pointer operator->();
  const_pointer operator->() const;

  // Property:
  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both
  // increased.
  __tree_iterator &operator++();
  __tree_iterator operator++(int);

  // Property:
  // Can be decremented (if a dereferenceable iterator value precedes it).
  __tree_iterator &operator--();
  __tree_iterator operator--(int);

  // Property:
  // Can be compared for equivalence using the equality/inequality operators
  // (meaningful when both iterator values iterate over the same underlying
  // sequence).
  friend bool operator==(const __tree_iterator &lhs,
                         const __tree_iterator &rhs) {
    return &*lhs == &*rhs;
  }
  friend bool operator!=(const __tree_iterator &lhs,
                         const __tree_iterator &rhs) {
    return !(lhs == rhs);
  }

private:
  typedef NodePtr node_pointer;

  explicit __tree_iterator(node_pointer ptr) : ptr_(ptr) {}

  template <class, class, class> friend class __tree;
  template <class, class, class> friend class __tree_iterator;
  template <class> friend class map_iterator;
  template <class, class, class, class> friend class map;

public:
  node_pointer ptr_;
};

} // namespace ft

#include "__tree_iterator.tpp"

#endif // VECTORE_ITERATOR_HPP_
