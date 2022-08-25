#ifndef HX_TREE_HPP_
#define HX_TREE_HPP_

#include <__tree>
#include <cstddef>     // ptrdiff_t
#include <functional>  // less
#include <iostream>
#include <iterator>  // bidirectional_tag
#include <memory>    // allocator

#include "../iterator/iterator.hpp"  // reverse_iterator
#include "../utility/utility.hpp"    // pair

namespace ft {

template <class NodePtr>
bool treeIsLeftChild(NodePtr np) {
  return np == np->parent->left;
}

template <class NodePtr>
NodePtr treeMax(NodePtr np) {
  while (np->right != NULL) {
    np = np->right
  };
  return np;
}

template <class NodePtr>
NodePtr treeMin(NodePtr np) {
  if (!np) return 0;
  while (np->left != NULL) np = np->left;
  return np;
}

template <class NodePtr>
NodePtr treeNext(NodePtr np) {
  if (np->right) {
    return treeMin(np->right);
  }
  while (treeIsLeftChild(np) == false) {
    np = np->parent;
  }
  return (np->parent);
}

template <class NodePtr>
NodePtr treePrev(NodePtr np) {
  if (np->left != NULL) return treeMax(np->left);
  while (treeIsLeftChild(np)) {
    np = np->parent;
  }
  return (np->parent);
}

template <class NodePtr>
NodePtr treeLeaf(NodePtr np) {
  while (1) {
    if (np->left) {
      np = np->left;
      continue;
    }
    if (np->right) {
      np = np->right;
      continue;
    }
    break;
  }
  return np;
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
class hx_iterator {
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
  hx_iterator() : np(0) {}
  // hx_iterator(const hx_iterator& other) : np(other.np) {}
  hx_iterator(const hx_iterator<value_type, ft::hx_node<value_type> >& other) : np(other.np) {}
  hx_iterator& operator=(const hx_iterator& other) {
    if (this == &other) return *this;
    this->np = other.np;
    return *this;
  }
  ~hx_iterator() {}

  // Property:
  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  reference operator*() { return this->np->value; }
  const_reference operator*() const { return this->np->value; }
  pointer operator->() { return &(this->np->value); }
  const_pointer operator->() const { return &(this->np->value); }
  // Property:
  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both
  // increased.
  hx_iterator& operator++() {
    this->np = treeNext(this->np);
    return *this;
  }
  hx_iterator operator++(int) {
    hx_iterator tmp(*this);
    ++tmp;
    *this = tmp;
    return --tmp;
  }
  // Property:
  // Can be decremented (if a dereferenceable iterator value precedes it).
  hx_iterator& operator--() {
    this->np = treePrev(this->np);
    return *this;
  }
  hx_iterator operator--(int) {
    hx_iterator tmp(*this);
    --tmp;
    *this = tmp;
    return ++tmp;
  }
  // Property:
  // Can be compared for equivalence using the equality/inequality operators
  // (meaningful when both iterator values iterate over the same underlying
  // sequence).
  friend bool operator==(const hx_iterator& lhs, const hx_iterator& rhs) { return &*lhs == &*rhs; }
  friend bool operator!=(const hx_iterator& lhs, const hx_iterator& rhs) { return !(lhs == rhs); }

 private:
  explicit hx_iterator(node_pointer np) : np(np) {}

  typedef NodeType* node_pointer;

  node_pointer np;

  template <class, class, class>
  friend class hx_tree;  // explicit TreeIterator(node_pointer);
                         // template <class, class> friend class hx_iterator;
};

template <class T, class _Comp = std::less<T>, class _Alloc = std::allocator<T> >
class hx_tree {
 public:
  typedef hx_node<T> node_type;
  typedef node_type* node_pointer;
  typedef T value_type;
  typedef _Comp value_compare;
  typedef typename _Alloc::template rebind<node_type>::other allocator_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef hx_iterator<value_type, node_type> iterator;
  typedef hx_iterator<value_type, const node_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  hx_tree(const value_compare& comp = value_compare(),
          const allocator_type& alloc = allocator_type())
      : alloc(alloc),
        root(0),
        begin_node(value_type()),
        end_node(value_type()),
        size(0),
        comp(comp) {
    begin_node.parent = &end_node;
  }

  template <class InputIterator>
  hx_tree(InputIterator first, InputIterator last, const value_compare& comp = value_compare(),
          const allocator_type& alloc = allocator_type())
      : alloc(alloc),
        root(0),
        begin_node(value_type()),
        end_node(value_type()),
        size(0),
        comp(comp) {
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
        size(0),
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
      while (current) {
        if (comp(current->value, value) != 0) {
          if (!current->right) {
            current->right = new_np;
            current->right->set_parent(current);
            break;
          }
          current = current->right;
        } else {
          if (!current->left) {
            current->left = new_np;
            current->left->set_parent(current);
            break;
          }
          current = current->left;
        }
      }
    }
    this->size++;
    this->begin_node.set_parent(ft::treeMin(end_node.left));
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
    if (found == this->end()) return 0;

    node_pointer tmp;
    if (found.np->left == 0 && found.np->right == 0) {
      if (ft::treeIsLeftChild(found.np)) {
        tmp = found.np->parent->left;
        found.np->parent->left = 0;
      } else {
        tmp = found.np->parent->right;
        found.np->parent->right = 0;
      }
    } else if (found.np->left != 0 && found.np->right != 0) {
      node_pointer subroot = ft::treeMax(found.np->left);
      if (ft::treeIsLeftChild(subroot)) {
        if (ft::treeIsLeftChild(found.np)) {
          found.np->parent->left = subroot;
        } else {
          found.np->parent->right = subroot;
        }
        subroot->set_parent(found.np->parent);
      } else {
        if (ft::treeIsLeftChild(found.np)) {
          found.np->parent->left = subroot->left;
        } else {
          subroot->parent->right = subroot->left;
        }
        subroot->left->set_parent(subroot->parent);
        subroot->left = found.np->left;
      }
      subroot->right = found.np->right;
      subroot->right->set_parent(subroot);
    } else {
      if (ft::treeIsLeftChild(found.np)) {
        tmp = found.np->parent->left;
        if (found.np->left) {
          found.np->parent->left = found.np->left;
          found.np->left->set_parent(found.np->parent);
        } else {
          found.np->parent->left = found.np->right;
          found.np->right->set_parent(found.np->parent);
        }
      } else {
        tmp = found.np->parent->right;
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
    this->size--;
    this->begin_node.set_parent(ft::treeMin(end_node.left));
    return 1;
  }

  void erase(iterator first, iterator last) {
    while (first != last) {
      this->erase(*first++);
    }
  }

  void clear() {
    this->clear_recursive(end_node.left);
    root = 0;
    end_node.left = 0;
    begin_node.parent = 0;
  }

  void swap(hx_tree& other) {
    hx_tree tmp = *this;
    *this = other;
    other = tmp;
  }

  value_compare value_comp() const { return value_compare(); }

  const_iterator find(const value_type& value) const {
    node_pointer current = this->end_node.left;
    while (current) {
      if (comp(current->value, value) == comp(value, current->value)) return iterator(current);
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
      if (comp(current->value, value) == comp(value, current->value)) return iterator(current);
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

  size_type _size() const { return this->size; }

  bool empty() const { return this->size == 0; }

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
  size_type size;
  value_compare comp;

  template <class, class, class>
  friend class hx_tree_iterator;
  template <class, class, class, class>
  friend class map;
};

}  // namespace ft

#endif  // HX_TREE_HPP_