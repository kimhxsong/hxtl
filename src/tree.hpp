#ifndef TREE_HPP_
#define TREE_HPP_
#include <iostream>
#include <iterator>
#include <memory>

#include <__tree>
#include "functional.hpp"

namespace ft {

template<typename T, typename NodePtr, typename DiffType>
class ft_tree_iterator {

public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef DiffType difference_type;
  typedef value_type& reference;
  typedef value_type* pointer;

  ft_tree_iterator() {}

  reference operator*() const {
  return ptr_->value_;
  }
   
  pointer operator->() const {
    return &(ptr_->value_);
  }

  ft_tree_iterator& operator++() {
    ptr_ = ft_tree_next(ptr_);
    return *this;
  }

  ft_tree_iterator operator++(int) {
    ft_tree_iterator tmp(*this);
    ++(*this);
    return tmp;
  }

  ft_tree_iterator& operator--() {
    ptr_ = ft_tree_prev(ptr_);
    return *this;
  }
  
  ft_tree_iterator operator--(int) {
    ft_tree_iterator tmp(*this);
    --(*this);
    return tmp;
  }

  friend bool operator==(const ft_tree_iterator& __x, const ft_tree_iterator& __y) {
    return __x.ptr_ == __y.ptr_;
  }

  friend bool operator!=(const ft_tree_iterator& __x, const ft_tree_iterator& __y) {
    return !(__x == __y);
  }

private:
  typedef NodePtr node_pointer;

  explicit ft_tree_iterator(node_pointer ptr) : ptr_(ptr) {}

  template <class, class, class> friend class ft_tree;
  // template <class, class, class> friend class __tree_const_iterator;
  template <class> friend class map_iterator;
  template <class, class, class, class> friend class map;
  // template <class, class, class> friend class set;

  node_pointer ptr_;
};

template <class T>
class ft_tree_node {
 public:
  typedef T value_type;
  // typedef T* pointer;
  // typedef T& reference;
  typedef ft_tree_node<T> node_type;

  ft_tree_node(const value_type& value)
    : parent_(0),
      right_(0),
      left_(0),
      value_(value) {
    std::cout << __func__ << std::endl;
  }

  void set_parent(node_type* parent) { parent_ = parent; }

  node_type* parent_;
  node_type* right_;
  node_type* left_;
  value_type value_;

  ~ft_tree_node() {}

//  private:
  // ft_tree_node(ft_tree_node const&);  // EQUAL TO DELETE
  // ft_tree_node& operator=(ft_tree_node const&);  // EQUAL TO DELETE
};

template <class T, class Compare, class Allocator>
class ft_tree {
 public:
  typedef T value_type;
  typedef Compare value_compare;
  typedef ft_tree_node<value_type> node_type;
  typedef typename Allocator::template rebind<node_type>::other allocator_type;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef ft_tree_iterator<value_type, allocator_type, difference_type> iterator;

  explicit ft_tree(const value_compare& comp = value_compare(),
                   const allocator_type& alloc = allocator_type())
    : alloc_(alloc),
      comp_(comp),
      end_node_(value_type()),
      root_(0),
      size_(0) {}

  ~ft_tree() {
    clear();
  }

  void insert(const value_type& value) {
    if (!root_) {
      root_ = alloc_.allocate(1);
      alloc_.construct(root_, value);
      root_->parent_ = &end_node_;
      end_node_.left_ = root_;
      size_++;
      return;
    }

    node_type* current = root_;
    while (current) {
      if (current->value_ == value) {
        return;
      }

      if (current->value_ < value) {
        if (current->right_ == NULL) {
          current->right_ = alloc_.allocate(1);  // To Fix
          alloc_.construct(current->right_, value);
          current->right_->parent_ = current;
          return;
        }
        current = current->right_;
      } else {
        if (current->left_ == NULL) {
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
    clear_recursive(root_);
  }


  node_type* tree_min(node_type* np) {
    while (np->right_ != NULL)
      np = np->right_;
    return np;
  }
  
  node_type* tree_max(node_type* np) {
    while (np->left_ != NULL)
      np = np->left_;
    return np;
  }

  node_type* tree_next(node_type* np) {
    if (np->right_ != 0) {
      return tree_min(np->right_);
    }
    while (tree_is_left_child(np) == false) {
      np = np->parent_;
    }
    return (np->parent_);
  }

  node_type* tree_prev(node_type* np) {
    if (np->left_ != NULL)
      return tree_max(np->left_);
    while (tree_is_left_child(np)) {
      np = np->parent_;
    }
    return (np);
  }

  node_type* tree_leaf(node_type* np) {
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
  // treebegin() {

  // }
  // end()
  // rbegin();
  // rend();
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
    node_type* root_;
    value_compare comp_;
    size_type size_;
};

}  // namespace ft

#endif  // TREE_HPP_