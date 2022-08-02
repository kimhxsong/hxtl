#ifndef TREE_HPP_
#define TREE_HPP_
#include <iostream>
#include <iterator>
#include <memory>

#include <__tree>
#include "functional.hpp"
#include "./iterator/reverse_iterator.hpp"

namespace ft {

static int calls = 0;

template <class T>
class __tree_node {
 public:
  typedef T value_type;
  // typedef T* pointer;
  // typedef T& reference;
  typedef __tree_node<T> node_type;
  typedef node_type* pointer;

  __tree_node(const value_type& value);

  void set_parent(node_type* parent);

  node_type* parent_;
  node_type* right_;
  node_type* left_;
  value_type value_;

  ~__tree_node();

//  private:
  // __tree_node(__tree_node const&);  // EQUAL TO DELETE
  // __tree_node& operator=(__tree_node const&);  // EQUAL TO DELETE
};

template <class NodePtr>
bool tree_is_left_child(NodePtr np);
template <class NodePtr>
NodePtr tree_max(NodePtr np);
template <class NodePtr>
NodePtr tree_min(NodePtr np);
template <class NodePtr>
NodePtr tree_next(NodePtr np);
template <class NodePtr>
NodePtr tree_prev(NodePtr np);
template <class NodePtr>
NodePtr tree_leaf(NodePtr np);

// template class __tree_iterator<class, class, class> is Bidirectional iterators
template<typename T, typename NodePtr, typename DiffType>
class __tree_iterator {
 public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef DiffType difference_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  // typedef NodePtr node_pointer;

// Property:
// Is default-constructible, copy-constructible, copy-assignable and destructible
  __tree_iterator();
  __tree_iterator(const __tree_iterator& other);
  __tree_iterator& operator=(const __tree_iterator& other);
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
// Two iterators that compare equal, keep comparing equal after being both increased.
  __tree_iterator& operator++();
  __tree_iterator operator++(int);

// Property:
// Can be decremented (if a dereferenceable iterator value precedes it).
  __tree_iterator& operator--();
  __tree_iterator operator--(int);

// Property:
// Can be compared for equivalence using the equality/inequality operators
// (meaningful when both iterator values iterate over the same underlying sequence).
  friend bool operator==(const __tree_iterator& lhs,
                         const __tree_iterator& rhs) {
    return &*lhs == &*rhs;
  }
  friend bool operator!=(const __tree_iterator& lhs,
                         const __tree_iterator& rhs) {
    return !(lhs == rhs);
  }

 private:
  typedef NodePtr node_pointer;

  explicit __tree_iterator(node_pointer ptr) : ptr_(ptr) {}

  template <class, class, class> friend class __tree;
  // template <class, class, class> friend class __tree_const_iterator;
  template <class> friend class __tree_const_iterator;
  template <class> friend class map_iterator;
  template <class, class, class, class> friend class map;
  // template <class, class, class> friend class set;

  node_pointer ptr_;
};

// TREE_CONST_ITERATOR
// template<typename T, typename NodePtr, typename DiffType>
// class __tree_const_iterator {
//   public:
//   typedef std::bidirectional_iterator_tag iterator_category;
//   typedef T value_type;
//   typedef DiffType difference_type;
//   typedef value_type& reference;
//   typedef value_type* pointer;

//   __tree_const_iterator() {}

//   // __tree_const_iterator(const non_const_iterator_type& it) : ptr_(it->ptr_) {}

//   reference operator*() const {
//   return ptr_->value_;
//   }
   
//   pointer operator->() const {
//     return &(ptr_->value_);
//   }

//   __tree_const_iterator& operator++() {
//     ptr_ = tree_next<node_pointer>(ptr_);
//     return *this;
//   }

//   __tree_const_iterator operator++(int) {
//     __tree_const_iterator tmp(*this);
//     ++(*this);
//     return tmp;
//   }

//   __tree_const_iterator& operator--() {
//     ptr_ = tree_prev<node_pointer>(ptr_);
//     return *this;
//   }
  
//   __tree_const_iterator operator--(int) {
//     __tree_const_iterator tmp(*this);
//     --(*this);
//     return tmp;
//   }

//   friend bool operator==(const __tree_const_iterator& np, const __tree_const_iterator& __y) {
//     return np.ptr_ == __y.ptr_;
//   }

//   friend bool operator!=(const __tree_const_iterator& np, const __tree_const_iterator& __y) {
//     return !(np == __y);
//   }

// private:
//   typedef NodePtr node_pointer;

//   explicit __tree_const_iterator(node_pointer ptr) : ptr_(ptr) {}

//   template <class, class, class> friend class __tree;
//   // template <class, class, class> friend class __tree_const_iterator;
//   template <class> friend class map_iterator;
//   template <class, class, class, class> friend class map;
//   // template <class, class, class> friend class set;

//   node_pointer ptr_;
// };


template <class T, class Compare, class Allocator>
class __tree {
 public:
  typedef T value_type;
  typedef Compare value_compare;
  typedef __tree_node<value_type> node_type;
  typedef typename Allocator::template rebind<node_type>::other allocator_type;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef __tree_iterator<value_type, node_type*, difference_type> iterator;  // 실수 있었음.
  // typedef __tree_const_iterator<iterator> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  explicit __tree(const value_compare& comp = value_compare(),
                  const allocator_type& alloc = allocator_type());
// operator= <-- TODO
  ~__tree();

  iterator begin();
  // const_iterator begin() const;
  iterator end();
  // const_iterator end() const;
  reverse_iterator rbegin();
  // const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  // const_reverse_iterator rend() const;

  void insert(const value_type& value);
  void clear();

  allocator_type __get_allocator();

  private:
    void clear_recursive(node_type* np);

    allocator_type alloc_;
    node_type end_node_;
    node_type begin_node_;
    node_type* root_;
    value_compare comp_;
    size_type size_;

    template <class, class, class> friend class __tree_iterator;
};

}  // namespace ft

#include "tree.tpp"

#endif  // TREE_HPP_