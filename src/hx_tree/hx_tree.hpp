#ifndef HX_TREE_HPP_
#define HX_TREE_HPP_

#include <__tree>
#include <cstddef>     // ptrdiff_t
#include <functional>  // less
#include <iostream>
#include <iterator>  // bidirectional_tag
#include <memory>    // allocator

#include "../algorithm/algorithm.hpp"
#include "../iterator/iterator.hpp"  // reverse_iterator
#include "../utility/utility.hpp"    // pair

namespace ft {

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
  if (!np) return 0;
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
class hx_node {
 public:
  typedef hx_node<T> node_type;
  typedef node_type* node_pointer;
  typedef T value_type;

  hx_node(const value_type& value) : parent(0), right(0), left(0), value(value) {}
  void set_parent(node_pointer parent) { this->parent = parent; }
  ~hx_node() {}

  node_pointer parent;
  node_pointer right;
  node_pointer left;
  value_type value;

 private:
  // equal to delete
  hx_node(hx_node const&);
  hx_node& operator=(hx_node const&);
};

template <class T, class NodeType>
class hx_tree_iterator {
 public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef std::ptrdiff_t difference_type;
  // Property:
  // Is default-constructible, copy-constructible, copy-assignable and
  // destructible
  hx_tree_iterator() : np(0) {}
  hx_tree_iterator(const hx_tree_iterator& other) : np(other.np) {}
  ~hx_tree_iterator() {}
  hx_tree_iterator& operator=(const hx_tree_iterator& other) {
    if (this == &other) {
      return *this;
    }
    this->np = other.np;
    return *this;
  }

  // Property:
  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  reference operator*() const { return this->np->value; }
  // const_reference operator*() const { return this->np->value; }
  pointer operator->() const { return &(this->np->value); }
  // const_pointer operator->() const { return &(this->np->value); }
  // Property:
  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both
  // increased.
  hx_tree_iterator& operator++() {
    this->np = ft::__tree_next(this->np);
    return *this;
  }
  hx_tree_iterator operator++(int) {
    hx_tree_iterator tmp(*this);
    ++(*this);
    return tmp;
  }
  // Property:
  // Can be decremented (if a dereferenceable iterator value precedes it).
  hx_tree_iterator& operator--() {
    this->np = __tree_prev(this->np);
    return *this;
  }

  hx_tree_iterator operator--(int) {
    hx_tree_iterator tmp(*this);
    --(*this);
    return tmp;
  }
  // Property:
  // Can be compared for equivalence using the equality/inequality operators
  // (meaningful when both iterator values iterate over the same underlying
  // sequence).
  friend bool operator==(const hx_tree_iterator& lhs, const hx_tree_iterator& rhs) {
    return lhs.np == rhs.np;
  }
  friend bool operator!=(const hx_tree_iterator& lhs, const hx_tree_iterator& rhs) {
    return !(lhs == rhs);
  }

 private:
  typedef NodeType* node_pointer;

  explicit hx_tree_iterator(node_pointer np) : np(np) {}

  node_pointer np;

  template <class, class, class>
  friend class hx_tree;  // explicit TreeIterator(node_pointer);
                         // template <class, class> friend class hx_tree_iterator;
  template <class, class>
  friend class hx_tree_const_iterator;
};

template <class T, class NodeType>
class hx_tree_const_iterator {
 public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef std::ptrdiff_t difference_type;
  typedef ft::hx_tree_iterator<value_type, ft::hx_node<value_type> > non_const_iterator;

  hx_tree_const_iterator() : np(0) {}
  hx_tree_const_iterator(const hx_tree_const_iterator& other) : np(other.np) {}
  hx_tree_const_iterator(const non_const_iterator& other) : np(other.np) {}
  ~hx_tree_const_iterator() {}

  hx_tree_const_iterator& operator=(const hx_tree_const_iterator& other) {
    if (this == &other) return *this;
    this->np = other.np;
    return *this;
  }

  reference operator*() const { return this->np->value; }
  // pointer operator->() { return &(this->np->value); }
  // pointer operator->() { return &(this->np->value); }
  pointer operator->() const { return &(this->np->value); }
  // Property:
  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both
  // increased.
  hx_tree_const_iterator& operator++() {
    this->np = ft::__tree_next(this->np);
    return *this;
  }
  hx_tree_const_iterator operator++(int) {
    hx_tree_const_iterator tmp(*this);
    ++(*this);
    return tmp;
  }
  // Property:
  // Can be decremented (if a dereferenceable iterator value precedes it).
  hx_tree_const_iterator& operator--() {
    this->np = __tree_prev(this->np);
    return *this;
  }
  hx_tree_const_iterator operator--(int) {
    hx_tree_const_iterator tmp(*this);
    --(*this);
    return tmp;
  }
  // Property:
  // Can be compared for equivalence using the equality/inequality operators
  // (meaningful when both iterator values iterate over the same underlying
  // sequence).
  friend bool operator==(const hx_tree_const_iterator& lhs, const hx_tree_const_iterator& rhs) {
    return lhs.np == rhs.np;
  }
  friend bool operator!=(const hx_tree_const_iterator& lhs, const hx_tree_const_iterator& rhs) {
    return !(lhs == rhs);
  }

 private:
  typedef NodeType node_type;
  typedef node_type* node_pointer;
  typedef const node_pointer const_node_pointer;

  explicit hx_tree_const_iterator(const_node_pointer np) : np(np) {}

  node_pointer np;

  template <class, class, class>
  friend class hx_tree;  // explicit TreeIterator(node_pointer);
                         // template <class, class> friend class hx_tree_iterator;
};

template <class T, class Comp = std::less<T>, class Alloc = std::allocator<T> >
class hx_tree {
 public:
  typedef hx_node<T> node_type;
  typedef node_type* node_pointer;
  typedef T value_type;
  typedef Comp value_compare;
  typedef typename Alloc::template rebind<node_type>::other allocator_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef hx_tree_iterator<value_type, node_type> iterator;
  typedef hx_tree_const_iterator<value_type, const node_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  hx_tree(const value_compare& comp = value_compare(),
          const allocator_type& alloc = allocator_type())
      : alloc(alloc), root(0), begin_node(value_type()), end_node(value_type()), sz(0), comp(comp) {
    begin_node.parent = &end_node;
  }

  template <class InputIterator>
  hx_tree(InputIterator first, InputIterator last, const value_compare& comp = value_compare(),
          const allocator_type& alloc = allocator_type())
      : alloc(alloc), root(0), begin_node(value_type()), end_node(value_type()), sz(0), comp(comp) {
    while (first != last) {
      this->insert(*first++);
    }
  }

  void copy_recursive(node_pointer np) {
    if (!np) return;
    this->insert(np->value);
    copy_recursive(np->left);
    copy_recursive(np->right);
  }

  hx_tree(const hx_tree& other)
      : alloc(other.alloc),
        root(0),
        begin_node(value_type()),
        end_node(value_type()),
        sz(0),
        comp(other.comp) {
    copy_recursive(other.end_node.left);
  }

  hx_tree& operator=(const hx_tree& other) {
    this->clear();
    copy_recursive(other.end_node.left);
    return *this;
  }
  ~hx_tree() { this->clear(); }

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
      return ft::make_pair(insert(this->end(), value), true);
  }

  iterator insert(iterator position, const value_type& value) {
    node_pointer new_np = this->alloc.allocate(1);
    this->alloc.construct(new_np, value);

    if (!root) {
      this->root = new_np;
      this->root->set_parent(&end_node);
      this->end_node.left = root;
    } else {
      node_pointer current = position.np->left;
      if (!current || comp(current->value, value)) {
        current = end_node.left;
      }
      // node_pointer current = position.np;
      while (current) {
        if (comp(current->value, value) == comp(value, current->value)) {
          this->alloc.destroy(new_np);
          this->alloc.deallocate(new_np, 1);
          return iterator(current);
        } else if (comp(current->value, value)) {
          if (!current->right) {
            new_np->set_parent(current);
            current->right = new_np;
            break;
          }
          current = current->right;
        } else {
          if (!current->left) {
            new_np->set_parent(current);
            current->left = new_np;
            break;
          }
          current = current->left;
        }
      }
    }
    this->sz++;
    this->begin_node.set_parent(ft::__tree_min(end_node.left));
    return iterator(new_np);
  }

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
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

    node_pointer tmp = found.np;
    if (found.np->left == 0 && found.np->right == 0) {
      if (ft::__tree_is_left_child(found.np)) {
        found.np->parent->left = 0;
      } else {
        found.np->parent->right = 0;
      }
    } else if (found.np->left != 0 && found.np->right != 0) {
      node_pointer subroot = ft::__tree_max(found.np->left);
      if (ft::__tree_is_left_child(found.np)) {
        found.np->parent->left = subroot;
      } else {
        found.np->parent->right = subroot;
      }
      if (!ft::__tree_is_left_child(subroot)) {
        subroot->parent->right = subroot->left;
        if (subroot->left) {
          subroot->left->set_parent(subroot->parent);
        }
        subroot->left = found.np->left;
        subroot->left->set_parent(subroot);
      }
      subroot->right = found.np->right;
      subroot->right->set_parent((subroot));
      subroot->set_parent(found.np->parent);
      subroot->right->set_parent(subroot);
    } else {
      if (ft::__tree_is_left_child(found.np)) {
        // tmp = found.np->parent->left;
        if (found.np->left) {
          found.np->parent->left = found.np->left;
          found.np->left->set_parent(found.np->parent);
        } else {
          found.np->parent->left = found.np->right;
          found.np->right->set_parent(found.np->parent);
        }
      } else {
        // tmp = found.np->parent->right;
        if (found.np->left) {
          found.np->parent->right = found.np->left;
          found.np->left->set_parent(found.np->parent);
        } else {
          found.np->parent->right = found.np->right;
          found.np->right->set_parent(found.np->parent);
        }
      }
    }
    this->alloc.destroy(tmp);
    this->alloc.deallocate(tmp, 1);
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
    this->clear_recursive(end_node.left);
    this->root = 0;
    this->end_node.left = 0;
    this->begin_node.parent = &end_node;
    this->sz = 0;
  }

  void swap(hx_tree& other) {
    node_pointer tmp_np = other.end_node.left;
    other.end_node.left = this->end_node.left;
    this->end_node.left = tmp_np;
    other.end_node.left->parent = &other.end_node;
    this->end_node.left->parent = &this->end_node;
    tmp_np = other.begin_node.parent;
    other.begin_node.parent = this->begin_node.parent;
    this->begin_node.parent = tmp_np;
    tmp_np = other.root;
    other.root = this->root;
    this->root = tmp_np;
    size_type tmp_sz = other.sz;
    other.sz = this->sz;
    this->sz = tmp_sz;
    allocator_type tmp_alloc = other.alloc;
    other.alloc = this->alloc;
    this->alloc = tmp_alloc;
    value_compare tmp_comp = other.comp;
    other.comp = this->comp;
    this->comp = tmp_comp;
  }

  value_compare value_comp() const { return value_compare(); }

  const_iterator find(const value_type& value) const {
    node_pointer current = this->end_node.left;
    while (current) {
      if (comp(current->value, value) == comp(value, current->value)) {
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
      if (comp(current->value, value) == comp(value, current->value)) {
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

  pair<iterator, iterator> equal_range(const value_type& value) {
    return make_pair(this->lower_bound(value), this->upper_bound(value));
  }

  pair<const_iterator, const_iterator> equal_range(const value_type& value) const {
    return make_pair(this->lower_bound(value), this->upper_bound(value));
  }

  allocator_type get_allocator() const { return this->alloc; }

  size_type size() const { return this->sz; }

  bool empty() const { return this->sz == 0; }

  size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(node_type); }

 private:
  void clear_recursive(node_pointer np) {
    if (!np) return;
    clear_recursive(np->left);
    clear_recursive(np->right);
    this->alloc.destroy(np);
    this->alloc.deallocate(np, 1);
  }

  allocator_type alloc;
  node_pointer root;
  node_type begin_node;
  node_type end_node;
  size_type sz;
  value_compare comp;

  template <class, class>
  friend class hx_tree_iterator;
  template <class, class>
  friend class hx_tree_const_iterator;
  template <class, class, class, class>
  friend class map;

  template <class _T, class _Comp, class _Alloc>
  friend bool operator==(const ft::hx_tree<_T, _Comp, _Alloc>& lhs,
                         const ft::hx_tree<_T, _Comp, _Alloc>& rhs) {
    return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
  }

  template <class _T, class _Comp, class _Alloc>
  friend bool operator<(const ft::hx_tree<_T, _Comp, _Alloc>& lhs,
                        const ft::hx_tree<_T, _Comp, _Alloc>& rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }
};

template <class T, class Comp, class Alloc>
bool operator!=(const ft::hx_tree<T, Comp, Alloc>& lhs, const ft::hx_tree<T, Comp, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class T, class Comp, class Alloc>
bool operator<=(const ft::hx_tree<T, Comp, Alloc>& lhs, const ft::hx_tree<T, Comp, Alloc>& rhs) {
  return !(lhs > rhs);
}

template <class T, class Comp, class Alloc>
bool operator>(const ft::hx_tree<T, Comp, Alloc>& lhs, const ft::hx_tree<T, Comp, Alloc>& rhs) {
  return rhs < lhs;
}

template <class T, class Comp, class Alloc>
bool operator>=(const ft::hx_tree<T, Comp, Alloc>& lhs, const ft::hx_tree<T, Comp, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class T, class Comp, class Alloc>
void swap(ft::hx_tree<T, Comp, Alloc>& lhs, ft::hx_tree<T, Comp, Alloc>& rhs) {
  return lhs.swap(rhs);
}

}  // namespace ft

#endif  // HX_TREE_HPP_