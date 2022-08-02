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


template <class NodePtr>
bool tree_is_left_child(NodePtr np) {
    return np == np->parent_->left_;
}

template <class NodePtr>
NodePtr tree_max(NodePtr np) {
  while (np->right_ != NULL)
    np = np->right_;
  return np;
}

template <class NodePtr>
NodePtr tree_min(NodePtr np) {
  while (np->left_ != NULL)
    np = np->left_;
  return np;
}

template <class NodePtr>
NodePtr tree_next(NodePtr np) {
  if (np->right_ != 0) {
    return tree_min<NodePtr>(np->right_);
  }
  while (tree_is_left_child<NodePtr>(np) == false) {
    np = np->parent_;
  }
  return (np->parent_);
}

template <class NodePtr>
NodePtr tree_prev(NodePtr np) {
  if (np->left_ != NULL)
    return tree_max<NodePtr>(np->left_);
  while (tree_is_left_child<NodePtr>(np)) {
    np = np->parent_;
  }
  return (np->parent_);
}

template <class NodePtr>
NodePtr tree_leaf(NodePtr np) {
  while (1) {
    if (np->left_) {
      np = np->left_;
      continue;
    }
    if (np->right_) {
      np = np->right_;
      continue;
    }
    break;
  }
  return np;
}

// TREE_ITERATOR
template<typename T, typename NodePtr, typename DiffType>
class __tree_iterator {

public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef DiffType difference_type;
  typedef value_type& reference;
  typedef value_type* pointer;
  // typedef NodePtr node_pointer;

  __tree_iterator() {}

  reference operator*() const {
  return ptr_->value_;
  }
   
  pointer operator->() const {
    return &(ptr_->value_);
  }

  __tree_iterator& operator++() {
    ptr_ = tree_next<node_pointer>(ptr_);
    return *this;
  }

  __tree_iterator operator++(int) {
    __tree_iterator tmp(*this);
    ++(*this);
    return tmp;
  }

  __tree_iterator& operator--() {
    ptr_ = tree_prev<node_pointer>(ptr_);
    return *this;
  }
  
  __tree_iterator operator--(int) {
    __tree_iterator tmp(*this);
    --(*this);
    return tmp;
  }

  friend bool operator==(const __tree_iterator& np, const __tree_iterator& __y) {
    return np.ptr_ == __y.ptr_;
  }

  friend bool operator!=(const __tree_iterator& np, const __tree_iterator& __y) {
    return !(np == __y);
  }

private:
  typedef NodePtr node_pointer;

  explicit __tree_iterator(node_pointer ptr) : ptr_(ptr) {}

  template <class, class, class> friend class __tree;
  // template <class, class, class> friend class __tree_const_iterator;
  template <class> friend class map_iterator;
  template <class, class, class, class> friend class map;
  // template <class, class, class> friend class set;

  node_pointer ptr_;
};

template <class T>
class __tree_node {
 public:
  typedef T value_type;
  // typedef T* pointer;
  // typedef T& reference;
  typedef __tree_node<T> node_type;
  typedef node_type* pointer;

  __tree_node(const value_type& value)
    : parent_(0),
      right_(0),
      left_(0),
      value_(value) {
    std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
  }

  void set_parent(node_type* parent) {
    std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
    parent_ = parent;
  }

  node_type* parent_;
  node_type* right_;
  node_type* left_;
  value_type value_;

  ~__tree_node() {
    std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
  }

//  private:
  // __tree_node(__tree_node const&);  // EQUAL TO DELETE
  // __tree_node& operator=(__tree_node const&);  // EQUAL TO DELETE
};


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
  // typedef __tree_iterator<value_type, node_type*, difference_type> iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;


//  constructor
  explicit __tree(const value_compare& comp = value_compare(),
                   const allocator_type& alloc = allocator_type())
    : alloc_(alloc),
      comp_(comp),
      begin_node_(value_type()),
      end_node_(value_type()),
      root_(0),
      size_(0) {}

// destructor
  ~__tree() {
    std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
    clear();
  }

// operator= <-- TODO


// iterators:
  iterator begin() {
    return iterator(tree_min(end_node_.left_));
  }
  // const_iterator begin() {
  //   return iterator(begin_np_);
  // }
  
  iterator end() {
    return iterator(&end_node_);
  }
  // const_iterator end() const {
  //   return iterator(&end_node_);
  // }

  reverse_iterator rbegin() {
    return reverse_iterator(end());
  }
  // const_iterator rbegin() {
  
  // }
  
  reverse_iterator rend() {
    node_type* np = tree_min(end_node_.left_);
    begin_node_.parent_ = np;
    begin_node_.parent_->left_ = &begin_node_;
    return reverse_iterator(iterator(np));
  }
  // const_iterator rend() const {

  // }

  void insert(const value_type& value) {
    std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
    if (!root_) {
      root_ = alloc_.allocate(1);
      alloc_.construct(root_, value);
      root_->parent_ = &end_node_;
      end_node_.left_ = root_;
      // begin_node.p = root_;
      size_++;
      return;
    }

    node_type* current = root_;
    while (current) {
      if (current->value_ == value) {
        std::cout << "중복!\n";
        return;
      }

      if (comp_(current->value_, value) != false) {
        if (!current->right_) {
          current->right_ = alloc_.allocate(1);  // To Fix
          alloc_.construct(current->right_, value);
          current->right_->parent_ = current;
          return;
        }
        current = current->right_;
      } else {
        if (!current->left_) {
          current->left_ = alloc_.allocate(1);  // TO Fix
          alloc_.construct(current->left_, value);
          current->left_->parent_ = current;
          return;
        }
        current = current->left_;
      }
    }
  }

  void clear() {
    std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
    clear_recursive(root_);
  }

  allocator_type __get_allocator() {
    return alloc_;
  }


  private:
    void clear_recursive(node_type* np) {
      if (!np)
        return;
      clear_recursive(np->left_);
      clear_recursive(np->right_);
      alloc_.destroy(np);
      alloc_.deallocate(np, 1);
    }

    allocator_type alloc_;
    node_type end_node_;
    node_type begin_node_;
    node_type* root_;
    value_compare comp_;
    size_type size_;

    template <class, class, class> friend class __tree_iterator;
};


}  // namespace ft

#endif  // TREE_HPP_