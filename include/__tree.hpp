#ifndef __TREE_HPP_
#define __TREE_HPP_

#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>

#include "__enable_if.hpp"
#include "__equal.hpp"
#include "__is_integral.hpp"
#include "__iterator_traits.hpp"
#include "__lexicographical_compare.hpp"
#include "__pair.hpp"
#include "__reverse_iterator.hpp"

namespace ft {

//
// Non Member __tree_node Utilities
//
template <class NodePtr>
bool __tree_is_left_child(NodePtr np) {
  return np == np->parent->left;
}

template <class NodePtr>
NodePtr __tree_max(NodePtr np) {
  while (np->right != NULL) {
    np = np->right;
  };

  return np;
}

template <class NodePtr>
NodePtr __tree_min(NodePtr np) {
  if (!np) {
    return 0;
  }

  while (np->left != NULL) {
    np = np->left;
  }

  return np;
}

template <class NodePtr>
NodePtr __tree_next(NodePtr np) {
  if (np->right) {
    return ft::__tree_min(np->right);
  }

  while (np->parent && !ft::__tree_is_left_child(np)) {
    np = np->parent;
  }

  return np->parent;
}

template <class NodePtr>
NodePtr __tree_prev(NodePtr np) {
  if (np->left) {
    return ft::__tree_max(np->left);
  }

  while (ft::__tree_is_left_child(np)) {
    np = np->parent;
  }

  return np->parent;
}

template <class T>
class __tree_node {
 public:
  typedef T value_type;

 private:
  typedef __tree_node<T> node_type;
  typedef node_type* node_pointer;

 public:
  node_pointer parent;
  node_pointer right;
  node_pointer left;
  value_type value;
  int height;

 public:
  __tree_node(const value_type& value) : parent(0), right(0), left(0), value(value), height(1) {}
  void set_parent(node_pointer parent) { this->parent = parent; }
  ~__tree_node() {}

 private:
  __tree_node();
  __tree_node(__tree_node const&);
  __tree_node& operator=(__tree_node const&);
};

template <class T, class NodeType>
class __tree_iterator {
 public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef typename ft::iterator_traits<T*>::difference_type difference_type;
  typedef typename ft::iterator_traits<T*>::value_type value_type;
  typedef typename ft::iterator_traits<T*>::pointer pointer;
  typedef typename ft::iterator_traits<T*>::reference reference;

 private:
  typedef NodeType* node_pointer;

  node_pointer np;

 public:
  __tree_iterator() : np(0) {}

  template <class _T, class _NodeType>
  __tree_iterator(const __tree_iterator<_T, _NodeType>& other) : np(other.base()) {}

  ~__tree_iterator() {}

  template <class _T, class _NodeType>
  __tree_iterator& operator=(const __tree_iterator<_T, _NodeType>& other) {
    if (this != &other) {
      this->np = other.base();
    }

    return *this;
  }

  explicit __tree_iterator(const node_pointer np) : np(np) {}
  node_pointer base() const { return this->np; }

  reference operator*() const { return this->np->value; }
  pointer operator->() const { return &(this->np->value); }

  __tree_iterator& operator++() {
    this->np = ft::__tree_next(this->np);
    return *this;
  }
  __tree_iterator operator++(int) {
    __tree_iterator tmp(*this);
    ++(*this);
    return tmp;
  }

  __tree_iterator& operator--() {
    this->np = __tree_prev(this->np);
    return *this;
  }
  __tree_iterator operator--(int) {
    __tree_iterator tmp(*this);
    --(*this);
    return tmp;
  }
};

template <class T1, class N1, class T2, class N2>
bool operator==(const __tree_iterator<T1, N1>& lhs, const __tree_iterator<T2, N2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class T1, class N1, class T2, class N2>
bool operator!=(const __tree_iterator<T1, N1>& lhs, const __tree_iterator<T2, N2>& rhs) {
  return !(lhs == rhs);
}

template <class T1, class N1, class T2, class N2>
bool operator<(const __tree_iterator<T1, N1>& lhs, const __tree_iterator<T2, N2>& rhs) {
  return lhs.base() > rhs.base();
}

template <class T1, class N1, class T2, class N2>
bool operator<=(const __tree_iterator<T1, N1>& lhs, const __tree_iterator<T2, N2>& rhs) {
  return !(rhs < lhs);
}

template <class T1, class N1, class T2, class N2>
bool operator>(const __tree_iterator<T1, N1>& lhs, const __tree_iterator<T2, N2>& rhs) {
  return rhs < lhs;
}

template <class T1, class N1, class T2, class N2>
bool operator>=(const __tree_iterator<T1, N1>& lhs, const __tree_iterator<T2, N2>& rhs) {
  return !(lhs < rhs);
}

template <class T, class Comp = std::less<T>, class Allocator = std::allocator<T> >
class __tree {
 private:
  typedef __tree_node<T> node_type;
  typedef node_type* node_pointer;

 public:
  typedef T value_type;
  typedef Comp value_compare;
  typedef typename Allocator::template rebind<node_type>::other allocator_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef ft::__tree_iterator<value_type, node_type> iterator;
  typedef ft::__tree_iterator<const value_type, const node_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  allocator_type alloc;
  node_type begin_node;
  node_type end_node;
  size_type sz;
  value_compare comp;

 public:
  __tree(const value_compare& comp = value_compare(),
         const allocator_type& alloc = allocator_type())
      : alloc(alloc), begin_node(value_type()), end_node(value_type()), sz(0), comp(comp) {
    begin_node.parent = &end_node;
  }

  template <class InputIterator>
  __tree(InputIterator first,
         typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
         const value_compare& comp = value_compare(),
         const allocator_type& alloc = allocator_type())
      : alloc(alloc), begin_node(value_type()), end_node(value_type()), sz(0), comp(comp) {
    begin_node.parent = &end_node;
    while (first != last) {
      this->insert(*first++);
    }
  }

  __tree(const __tree& other)
      : alloc(other.alloc),
        begin_node(value_type()),
        end_node(value_type()),
        sz(0),
        comp(other.comp) {
    __copy_recursive(other.end_node.left);
  }

  __tree& operator=(const __tree& other) {
    this->clear();
    __copy_recursive(other.end_node.left);
    return *this;
  }
  ~__tree() { this->clear(); }

  iterator begin() { return iterator(begin_node.parent); }
  const_iterator begin() const { return const_iterator(begin_node.parent); }
  iterator end() { return iterator(&end_node); }
  const_iterator end() const { return const_iterator(&end_node); }
  reverse_iterator rbegin() { return reverse_iterator(this->end()); }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
  reverse_iterator rend() { return reverse_iterator(this->begin()); }
  const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

  pair<iterator, bool> insert(const value_type& value) {
    iterator found = this->find(value);
    if (found != this->end())
      return ft::make_pair(found, false);
    else
      return ft::make_pair(this->insert(this->end(), value), true);
  }

  iterator insert(iterator position, const value_type& value) {
    iterator found = this->find(value);
    if (this->find(value) != this->end()) {
      return found;
    }

    node_pointer balance_np = this->alloc.allocate(1);
    this->alloc.construct(balance_np, value);
    if (!end_node.left) {
      balance_np->set_parent(&end_node);
      this->end_node.left = balance_np;
    } else {
      node_pointer current = position.base()->left;
      node_pointer prev = 0;
      if (!current || comp(current->value, value)) {
        current = end_node.left;
      }

      while (current) {
        if (comp(current->value, value)) {
          prev = current;
          current = current->right;
        } else {
          prev = current;
          current = current->left;
        }
      }

      if (comp(prev->value, value)) {
        prev->right = balance_np;
        balance_np->set_parent(prev);
      } else {
        prev->left = balance_np;
        balance_np->set_parent(prev);
      }

      this->__rebalance(balance_np);
    }

    this->sz++;
    this->begin_node.set_parent(ft::__tree_min(end_node.left));
    return iterator(balance_np);
  }

  template <class InputIterator>
  void insert(
      InputIterator first,
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
    while (first != last) {
      this->insert(*first++);
    }
  }

  void erase(iterator position) { this->erase(*position); }

  size_type erase(const value_type& val) {
    iterator found = this->find(val);
    if (found == this->end()) {
      return 0;
    }

    node_pointer del = found.base();
    node_pointer balance_np = del->parent;
    if (del->left == 0 && del->right == 0) {
      if (ft::__tree_is_left_child(del)) {
        del->parent->left = 0;
      } else {
        del->parent->right = 0;
      }
    } else if (del->left != 0 && del->right != 0) {
      node_pointer subroot = ft::__tree_max(del->left);
      if (ft::__tree_is_left_child(del)) {
        del->parent->left = subroot;
      } else {
        del->parent->right = subroot;
      }
      if (!ft::__tree_is_left_child(subroot)) {
        subroot->parent->right = subroot->left;
        if (subroot->left) {
          subroot->left->set_parent(subroot->parent);
        }

        subroot->left = del->left;
        subroot->left->set_parent(subroot);
      }

      subroot->right = del->right;
      subroot->right->set_parent((subroot));
      subroot->set_parent(del->parent);
      subroot->right->set_parent(subroot);
    } else {
      if (ft::__tree_is_left_child(del)) {
        if (del->left) {
          del->parent->left = del->left;
          del->left->set_parent(del->parent);
        } else {
          del->parent->left = del->right;
          del->right->set_parent(del->parent);
        }
      } else {
        if (del->left) {
          del->parent->right = del->left;
          del->left->set_parent(del->parent);
        } else {
          del->parent->right = del->right;
          del->right->set_parent(del->parent);
        }
      }
    }

    this->__rebalance(balance_np);
    this->alloc.destroy(del);
    this->alloc.deallocate(del, 1);
    this->sz--;
    this->begin_node.set_parent(ft::__tree_min(&end_node));
    return 1;
  }

  void erase(iterator first, iterator last) {
    while (first != last) {
      this->erase(*first++);
    }
  }

  void clear() {
    this->__clear_recursive(end_node.left);
    this->end_node.left = 0;
    this->begin_node.parent = &end_node;
    this->sz = 0;
  }

  void swap(__tree& other) {
    node_pointer tmp_np = 0;
    tmp_np = other.end_node.left;
    other.end_node.left = this->end_node.left;
    this->end_node.left = tmp_np;
    if (other.end_node.left) {
      other.end_node.left->parent = &other.end_node;
    }

    if (this->end_node.left) {
      this->end_node.left->parent = &this->end_node;
    }

    tmp_np = other.begin_node.parent;
    other.begin_node.parent = this->begin_node.parent;
    this->begin_node.parent = tmp_np;
    size_type tmp_sz = other.sz;
    other.sz = this->sz;
    this->sz = tmp_sz;
  }

  value_compare value_comp() const { return value_compare(); }

  const_iterator find(const value_type& value) const {
    node_pointer current = this->end_node.left;
    while (current) {
      if (!comp(current->value, value) && !comp(value, current->value)) {
        return iterator(current);
      }

      if (comp(current->value, value)) {
        current = current->right;
      } else {
        current = current->left;
      }
    }

    return this->end();
  }

  iterator find(const value_type& value) {
    node_pointer current = this->end_node.left;
    while (current) {
      if (!comp(current->value, value) && !comp(value, current->value)) {
        return iterator(current);
      }

      if (comp(current->value, value)) {
        current = current->right;
      } else {
        current = current->left;
      }
    }

    return this->end();
  }

  size_type count(const value_type& val) const { return this->find(val) != this->end() ? 1 : 0; }

  iterator lower_bound(const value_type& value) {
    node_pointer result = 0;
    node_pointer current = this->end_node.left;
    while (current) {
      if (!comp(current->value, value)) {
        result = current;
        current = current->left;
      } else
        current = current->right;
    }

    if (!result)
      return this->end();
    else
      return iterator(result);
  }

  const_iterator lower_bound(const value_type& value) const {
    node_pointer result = 0;
    node_pointer current = this->end_node.left;
    while (current) {
      if (!comp(current->value, value)) {
        result = current;
        current = current->left;
      } else
        current = current->right;
    }

    if (!result)
      return this->end();
    else
      return const_iterator(result);
  }

  iterator upper_bound(const value_type& value) {
    node_pointer result = 0;
    node_pointer current = this->end_node.left;
    while (current) {
      if (comp(value, current->value)) {
        result = current;
        current = current->left;
      } else
        current = current->right;
    }

    if (!result)
      return this->end();
    else
      return iterator(result);
  }

  const_iterator upper_bound(const value_type& value) const {
    node_pointer result = 0;
    node_pointer current = this->end_node.left;
    while (current) {
      if (comp(value, current->value)) {
        result = current;
        current = current->left;
      } else
        current = current->right;
    }

    if (!result)
      return this->end();
    else
      return const_iterator(result);
  }

  ft::pair<iterator, iterator> equal_range(const value_type& value) {
    return ft::make_pair(this->lower_bound(value), this->upper_bound(value));
  }

  ft::pair<const_iterator, const_iterator> equal_range(const value_type& value) const {
    return ft::make_pair(this->lower_bound(value), this->upper_bound(value));
  }

  size_type size() const { return this->sz; }

  bool empty() const { return this->sz == 0; }

  size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(node_type); }

 private:
  void __copy_recursive(node_pointer np) {
    if (!np) {
      return;
    }
    this->insert(np->value);
    __copy_recursive(np->left);
    __copy_recursive(np->right);
  }

  void __clear_recursive(node_pointer np) {
    if (!np) {
      return;
    }
    __clear_recursive(np->left);
    __clear_recursive(np->right);
    this->alloc.destroy(np);
    this->alloc.deallocate(np, 1);
  }

  int __tree_height(node_pointer root) {
    if (!root || root == &this->end_node) {
      return 0;
    }

    int left_height = root->left != 0 ? root->left->height : 0;
    int right_height = root->right != 0 ? root->right->height : 0;
    int max_height = left_height > right_height ? left_height : right_height;
    return max_height + 1;
  }

  int __tree_balance_factor(node_pointer np) {
    if (!np) {
      return 1;
    }

    return __tree_height(np->left) - __tree_height(np->right);
  }

  void __rotate_left(node_pointer down_np) {
    node_pointer up_np = down_np->right;
    down_np->right = up_np->left;
    if (up_np->left) {
      up_np->left->parent = down_np;
    }

    up_np->left = down_np;
    up_np->parent = down_np->parent;
    if (down_np->parent) {
      if (down_np->parent->left == down_np)
        down_np->parent->left = up_np;
      else
        down_np->parent->right = up_np;
    }

    down_np->parent = up_np;
    down_np->height = __tree_height(down_np);
    up_np->height = __tree_height(up_np);
  }

  void __rotate_right(node_pointer down_np) {
    node_pointer up_np = down_np->left;
    down_np->left = up_np->right;
    if (up_np->right) {
      up_np->right->parent = down_np;
    }

    up_np->right = down_np;
    up_np->parent = down_np->parent;
    if (down_np->parent) {
      if (down_np->parent->left == down_np)
        down_np->parent->left = up_np;
      else
        down_np->parent->right = up_np;
    }

    down_np->parent = up_np;
    down_np->height = __tree_height(down_np);
    up_np->height = __tree_height(up_np);
  }

  void __rebalance(node_pointer np) {
    while (np != &this->end_node) {
      np->height = __tree_height(np);
      int balance = __tree_balance_factor(np);
      if (balance < -1) {
        if (__tree_balance_factor(np->right) < 0) {
          __rotate_left(np);
        } else {
          __rotate_right(np->right);
          __rotate_left(np);
        }
      } else if (balance > 1) {
        if (__tree_balance_factor(np->left) > 0) {
          __rotate_right(np);
        } else {
          __rotate_left(np->left);
          __rotate_right(np);
        }
      }

      np = np->parent;
    }
  }
};  // class __tree

//
// Non Member Functions
//
template <class _T, class _Comp, class _Alloc>
bool operator==(const ft::__tree<_T, _Comp, _Alloc>& lhs,
                const ft::__tree<_T, _Comp, _Alloc>& rhs) {
  return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class _T, class _Comp, class _Alloc>
bool operator<(const ft::__tree<_T, _Comp, _Alloc>& lhs, const ft::__tree<_T, _Comp, _Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Comp, class Alloc>
bool operator!=(const ft::__tree<T, Comp, Alloc>& lhs, const ft::__tree<T, Comp, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class T, class Comp, class Alloc>
bool operator<=(const ft::__tree<T, Comp, Alloc>& lhs, const ft::__tree<T, Comp, Alloc>& rhs) {
  return !(lhs > rhs);
}

template <class T, class Comp, class Alloc>
bool operator>(const ft::__tree<T, Comp, Alloc>& lhs, const ft::__tree<T, Comp, Alloc>& rhs) {
  return rhs < lhs;
}

template <class T, class Comp, class Alloc>
bool operator>=(const ft::__tree<T, Comp, Alloc>& lhs, const ft::__tree<T, Comp, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class T, class Comp, class Alloc>
void swap(ft::__tree<T, Comp, Alloc>& lhs, ft::__tree<T, Comp, Alloc>& rhs) {
  return lhs.swap(rhs);
}

}  // namespace ft

#endif  // __TREE_HPP_