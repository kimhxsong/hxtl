#ifndef MAP_HPP_
#define MAP_HPP_

#include <functional>
#include <iostream>
#include <map>
#include <memory>

#include "../hx_tree/hx_tree.hpp"
#include "../utility/utility.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Alloc = std::allocator<pair<const Key, T> > >
class map {
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef Compare key_compare;
  typedef typename ft::pair<const key_type, mapped_type> value_type;

  class value_compare {
    friend class map;

   protected:
    key_compare comp;
    value_compare(key_compare comp) : comp(comp) {}

   public:
    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;
    bool operator()(const value_type& x, const value_type& y) const {
      return comp(x.first, y.first);
    }
  };

  typedef ft::hx_tree<value_type, value_compare, Alloc> map_base;
  typedef typename map_base::allocator_type allocator_type;
  typedef typename map_base::const_pointer const_pointer;
  typedef typename map_base::const_reference const_reference;
  typedef typename map_base::pointer pointer;
  typedef typename map_base::reference reference;
  typedef typename map_base::iterator iterator;
  typedef typename map_base::const_iterator const_iterator;
  typedef typename map_base::reverse_iterator reverse_iterator;
  typedef typename map_base::const_reverse_iterator const_reverse_iterator;
  typedef typename map_base::difference_type difference_type;
  typedef typename map_base::size_type size_type;

  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
      : base(value_compare(comp), alloc) {}
  template <class InputIterator>
  map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
      : base(first, last, value_compare(comp), alloc) {}
  map(const map& other) : base(other.base) {}
  ~map() {}

  map& operator=(const map& other) {
    this->base = other.base;
    return *this;
  }

  iterator begin() { return base.begin(); }
  const_iterator begin() const { return const_iterator(base.begin()); }
  iterator end() { return base.end(); }
  const_iterator end() const { return const_iterator(base.end()); }
  reverse_iterator rbegin() { return base.rbegin(); }
  const_reverse_iterator rbegin() const { return base.rbegin(); }
  reverse_iterator rend() { return base.rend(); }
  const_reverse_iterator rend() const { return base.rend(); }

  bool empty() const { return base.empty(); }

  size_type size() const { return base._size(); }

  size_type max_size() const { return base.max_size(); }

  mapped_type& operator[](const key_type& k) {
    iterator found = base.find(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
    if (found != this->end()) {
      std::cout << "test" << std::endl;
      return found->second;
    } else
      return base.insert(ft::make_pair<const key_type, mapped_type>(k, mapped_type()))
          .first->second;
  }

  pair<iterator, bool> insert(const value_type& value) { return base.insert(value); }
  iterator insert(iterator position, const value_type& value) {
    return base.insert(position, value);
  }
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    while (first != last) {
      base.insert(*first++);
    }
  }
  void erase(iterator position) { base.erase(position); }
  size_type erase(const key_type& k) {
    return base.erase(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  void erase(iterator first, iterator last) { base.erase(first, last); }
  void swap(map& other) { base.swap(other.base); }
  void clear() { base.clear(); }
  iterator find(const key_type& k) {
    return base.find(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  const_iterator find(const key_type& k) const {
    return base.find(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  size_type count(const key_type& k) const {
    return base.count(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  key_compare key_comp() const { return key_compare(); }
  value_compare value_comp() const { return value_compare(key_compare()); }
  iterator lower_bound(const key_type& k) {
    return base.lower_bound(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  const_iterator lower_bound(const key_type& k) const {
    return base.lower_bound(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  iterator upper_bound(const key_type& k) {
    return base.upper_bound(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  const_iterator upper_bound(const key_type& k) const {
    return base.upper_bound(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
    return base.equal_range(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  pair<iterator, iterator> equal_range(const key_type& k) {
    return base.equal_range(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
  }
  allocator_type get_allocator() const { return base.get_allocator(); }

 private:
  map_base base;
};

}  // namespace ft

#endif  // MAP_HPP_