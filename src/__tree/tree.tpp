#ifndef TREE_TPP_
#define TREE_TPP_

#include "tree.hpp"

namespace ft {

template <typename T>
__tree_node<T>::__tree_node(const value_type& value)
  : parent_(0),
    right_(0),
    left_(0),
    value_(value) {
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
}

template <typename T>
__tree_node<T>::~__tree_node() {
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
}

template <typename T>
void __tree_node<T>::set_parent(node_type* parent) {
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
  parent_ = parent;
}

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

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>::__tree_iterator() {}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>::__tree_iterator(const __tree_iterator& other)
  : ptr_(other.ptr_) {}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>&
__tree_iterator<T, NodePtr, DiffType>::operator=(const __tree_iterator& other) {
  if (this != &other) {
    this->ptr_ = other.ptr_;
  }
  return *this;
}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>::~__tree_iterator() {}

template<typename T, typename NodePtr, typename DiffType>
typename __tree_iterator<T, NodePtr, DiffType>::reference
__tree_iterator<T, NodePtr, DiffType>::operator*() {
  return ptr_->value_;
}

template<typename T, typename NodePtr, typename DiffType>
typename __tree_iterator<T, NodePtr, DiffType>::const_reference
__tree_iterator<T, NodePtr, DiffType>::operator*() const {
  return ptr_->value_;
}

template<typename T, typename NodePtr, typename DiffType>
typename __tree_iterator<T, NodePtr, DiffType>::pointer
__tree_iterator<T, NodePtr, DiffType>::operator->(){
  return &(ptr_->value_);
}

template<typename T, typename NodePtr, typename DiffType>
typename __tree_iterator<T, NodePtr, DiffType>::const_pointer
__tree_iterator<T, NodePtr, DiffType>::operator->() const {
  return &(ptr_->value_);
}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>&
__tree_iterator<T, NodePtr, DiffType>::operator++() {
  ptr_ = tree_next<node_pointer>(ptr_);
  return *this;
}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>
__tree_iterator<T, NodePtr, DiffType>::operator++(int) {
  __tree_iterator tmp(*this);
  ++(*this);
  return tmp;
}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>&
__tree_iterator<T, NodePtr, DiffType>::operator--() {
  ptr_ = tree_prev<node_pointer>(ptr_);
  return *this;
}

template<typename T, typename NodePtr, typename DiffType>
__tree_iterator<T, NodePtr, DiffType>
__tree_iterator<T, NodePtr, DiffType>::operator--(int) {
  __tree_iterator tmp(*this);
  --(*this);
  return tmp;
}


template <class T, class Compare, class Allocator>
__tree<T, Compare, Allocator>::__tree(const value_compare& comp,
                                      const allocator_type& alloc)
  : alloc_(alloc),
    comp_(comp),
    begin_node_(value_type()),
    end_node_(value_type()),
    root_(0),
    size_(0) {}

template <class T, class Compare, class Allocator>
__tree<T, Compare, Allocator>::~__tree() {
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
  clear();
}

// operator= <-- TODO


template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::begin() {
  return iterator(tree_min(end_node_.left_));
}

// const_iterator begin() const {
//   return const_iterator(begin());
// }

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>:: end() {
  return iterator(&end_node_);
}

// const_iterator end() const {
//   return const_iterator(end());
// }

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::reverse_iterator
__tree<T, Compare, Allocator>::rbegin() {
  return reverse_iterator(end());
}

// const_reverse_iterator rbegin() const {
//   return const_reverse_iteartor(const_iterator(end()));
// }

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::reverse_iterator
__tree<T, Compare, Allocator>:: rend() {
  return reverse_iterator(begin());
}

// const_reverse_iterator rend() const {
//   return const_reverse_iterator(const_iterator(begin()));
// }

template <class T, class Compare, class Allocator>
void
__tree<T, Compare, Allocator>::insert(const value_type& value) {
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
  if (!root_) {
    root_ = alloc_.allocate(1);
    alloc_.construct(root_, value);
    root_->parent_ = &end_node_;
    end_node_.left_ = root_;
    // begin_node.p = root_;`
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

template <class T, class Compare, class Allocator>
void
__tree<T, Compare, Allocator>::clear_recursive(node_type* np) {
  if (!np)
    return;
  clear_recursive(np->left_);
  clear_recursive(np->right_);
  alloc_.destroy(np);
  alloc_.deallocate(np, 1);
}

template <class T, class Compare, class Allocator>
void
__tree<T, Compare, Allocator>::clear() {
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__ << std::endl;
  clear_recursive(root_);
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::allocator_type
__tree<T, Compare, Allocator>::__get_allocator() {
  return alloc_;
}


}  // namespace ft

// 왜  오류?
// template<typename T, typename NodePtr, typename DiffType>
// bool
// operator==(const ft::__tree_iterator<T, NodePtr, DiffType>& lhs, const ft::__tree_iterator<T, NodePtr, DiffType>& rhs) {
//   return &*lhs == &*rhs;
// }

// template<typename T, typename NodePtr, typename DiffType>
// bool
// operator!=(const ft::__tree_iterator<T, NodePtr, DiffType>& lhs, const ft::__tree_iterator<T, NodePtr, DiffType>& rhs) {
//   return !(lhs == rhs);
// }

#endif  // TREE_TPP_