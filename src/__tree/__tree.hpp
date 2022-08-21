#ifndef TREE_HPP_
#define TREE_HPP_

#include <functional>
#include <iostream>
#include <iterator>
#include <memory>

#include "../utility/utility.hpp"
#include "__tree_iterator.hpp"

namespace ft
{

// 트리노드는 인스턴스가 생성될 때 반드시 값이 초기화되도록 설계했다.
template <class T> class __tree_node
{
 public:
  typedef __tree_node<T> node_type;
  typedef node_type* node_pointer;
  typedef T value_type;

  __tree_node(const value_type& value) : value_(value) {}
  void set_parent(node_pointer parent)
  {
    this->parent_ = parent;
  }
  ~__tree_node();

  node_pointer parent_;
  node_pointer right_;
  node_pointer left_;
  value_type value_;

 private:
  // equal to delete
  __tree_node(__tree_node const&);
  __tree_node& operator=(__tree_node const&);
};

template <class T,
          class Compare = std::less<T>,
          class Allocator = std::allocator<T> >
class __tree
{
 public:
  typedef __tree_node<value_type> node_type;
  typedef node_type* node_pointer;

  typedef T value_type;
  typedef Compare value_compare;
  typedef typename Allocator::template rebind<node_type>::other allocator_type;
  typedef value_type* pointer;
  typedef const pointer const_pointer;
  typedef value_type& reference;
  typedef const reference const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef __tree_iterator<value_type, node_pointer> iterator;
  typedef __tree_iterator<value_type, const node_pointer> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  __tree(const value_compare& comp = value_compare(),
         const allocator_type& alloc = allocator_type());
  ~__tree();

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  pair<iterator, bool> insert(const value_type& val);
  iterator insert(iterator position, const value_type& val);
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last);

  void erase(iterator position);
  size_type erase(const value_type& val);
  void erase(iterator first, iterator last);

  void clear();
  void swap(__tree& other);

  key_compare key_comp() const;
  value_compare value_comp() const;

  iterator find(const value_type& val);
  size_type count(const value_type& val);
  iterator lower_bound(const value_type& val);
  iterator upper_bound(const value_type& val);
  pair<iterator, iterator> equal_range(const value_type& val);
  allocator_type get_allocator();

 private:
  void clear_recursive(node_type* np);

  allocator_type alloc_;
  node_type end_node_;
  node_type begin_node_;
  node_pointer root_;
  value_compare comp_;
  size_type size_;

  template <class, class, class> friend class __tree_iterator;
};

}  // namespace ft

#include "__tree.tpp"

#endif  // TREE_HPP_