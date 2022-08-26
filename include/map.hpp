#ifndef MAP_HPP_
#define MAP_HPP_

#include <functional>
#include <iostream>
#include <memory>

#include "__enable_if.hpp"
#include "__is_integral.hpp"
#include "__pair.hpp"
#include "__reverse_iterator.hpp"
#include "__tree.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<pair<const Key, T> > >
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

 private:
  typedef ft::__tree<value_type, value_compare, Allocator> map_base;

 public:
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename map_base::iterator iterator;
  typedef typename map_base::const_iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
      : base(value_compare(comp), alloc) {}
  template <class InputIterator>
  map(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
      InputIterator last, const key_compare& comp = key_compare(),
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

  size_type size() const { return base.size(); }

  size_type max_size() const { return base.max_size(); }

  mapped_type& operator[](const key_type& k) {
    iterator found = base.find(ft::make_pair<const key_type, mapped_type>(k, mapped_type()));
    if (found != this->end()) {
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
  void insert(
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
      InputIterator last) {
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
  allocator_type get_allocator() const { return allocator_type(); }

 private:
  map_base base;

  template <class _Key, class _T, class _Comp, class _Alloc>
  friend bool operator==(const ft::map<_Key, _T, _Comp, _Alloc>& lhs,
                         const ft::map<_Key, _T, _Comp, _Alloc>& rhs) {
    return lhs.base == rhs.base;
  }
  template <class _Key, class _T, class _Comp, class _Alloc>
  friend bool operator<(const ft::map<_Key, _T, _Comp, _Alloc>& lhs,
                        const ft::map<_Key, _T, _Comp, _Alloc>& rhs) {
    return lhs.base < rhs.base;
  }
};

template <class Key, class T, class Comp, class Alloc>
bool operator!=(const ft::map<Key, T, Comp, Alloc>& lhs, const ft::map<Key, T, Comp, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class Key, class T, class Comp, class Alloc>
bool operator<=(const ft::map<Key, T, Comp, Alloc>& lhs, const ft::map<Key, T, Comp, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <class Key, class T, class Comp, class Alloc>
bool operator>(const ft::map<Key, T, Comp, Alloc>& lhs, const ft::map<Key, T, Comp, Alloc>& rhs) {
  return rhs < lhs;
}

template <class Key, class T, class Comp, class Alloc>
bool operator>=(const ft::map<Key, T, Comp, Alloc>& lhs, const ft::map<Key, T, Comp, Alloc>& rhs) {
  return !(lhs < rhs);
}

}  // namespace ft

#endif  // MAP_HPP_