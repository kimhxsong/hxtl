#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <iterator>

#include "functional.hpp"
#include "pair.hpp"
#include "iterator.hpp"
#include "tree.hpp"
#include <map>
#include <compare>
#include <initializer_list>
 
namespace ft {

  // class template map
  template<class Key, class T, class Compare = less<Key>,
           class Allocator = allocator<pair<const Key, T>>>
    class map;
  // (removed in C++20)
  template<class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key, T, Compare, Allocator>& x,
                    const map<Key, T, Compare, Allocator>& y);
  // (removed in C++20)
  template<class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key, T, Compare, Allocator>& x,
                    const map<Key, T, Compare, Allocator>& y);
  // (removed in C++20)
  template<class Key, class T, class Compare, class Allocator>
    bool operator<(const map<Key, T, Compare, Allocator>& x,
                    const map<Key, T, Compare, Allocator>& y);
  // (removed in C++20)
  template<class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key, T, Compare, Allocator>& x,
                    const map<Key, T, Compare, Allocator>& y);
  // (removed in C++20)
  template<class Key, class T, class Compare, class Allocator>
    bool operator>(const map<Key, T, Compare, Allocator>& x,
                    const map<Key, T, Compare, Allocator>& y);
  // (removed in C++20)
  template<class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key, T, Compare, Allocator>& x,
                    const map<Key, T, Compare, Allocator>& y);

  template<class Key, class T, class Compare, class Allocator>
    void swap(map<Key, T, Compare, Allocator>& x,
              map<Key, T, Compare, Allocator>& y);

  template<class Key, class T, class Compare = less<Key>,
           class Allocator = allocator<pair<const Key, T>>>
  class map {
  public:
    // types
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;
    typedef Allocator allocator_type;
    typedef typename allocator_traits<Allocator>::pointer pointer;
    typedef typename allocator_traits<Allocator>::const_pointer const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef /* implementation-defined */ size_type;
    typedef /* implementation-defined */ difference_type;
    typedef /* implementation-defined */ iterator;
    typedef /* implementation-defined */ const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef /* unspecified */ node_type;
    typedef /*insert-return-type*/<iterator, node_type> insert_return_type;
 
    class value_compare {
      friend class map;
    protected:
      Compare comp;
      value_compare(Compare c) : comp(c) {}
    public:
      bool operator()(const value_type& x, const value_type& y) const {
        return comp(x.first, y.first);
      }
    };
 
    // construct/copy/destroy
    map() : map(Compare()) { }
    explicit map(const Compare& comp, const Allocator& = Allocator());
    template<class InputIt>
      map(InputIt first, InputIt last,
          const Compare& comp = Compare(), const Allocator& = Allocator());
    map(const map& x);
    map(map&& x);
    explicit map(const Allocator&);
    map(const map&, const Allocator&);
    map(map&&, const Allocator&);

    template<class InputIt>
      map(InputIt first, InputIt last, const Allocator& a)
        : map(first, last, Compare(), a) { }
    map(initializer_list<value_type> il, const Allocator& a)
      : map(il, Compare(), a) { }
    ~map();
    map& operator=(const map& x);

    allocator_type get_allocator() const;
 
    // iterators
    iterator               begin() ;
    const_iterator         begin() const;
    iterator               end() ;
    const_iterator         end() const;
 
    reverse_iterator       rbegin() ;
    const_reverse_iterator rbegin() const;
    reverse_iterator       rend() ;
    const_reverse_iterator rend() const;
 
    const_iterator         cbegin() const;
    const_iterator         cend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
 
    // capacity
    [[nodiscard]] bool empty() const;
    size_type size() const;
    size_type max_size() const;
 
    // element access
    mapped_type& operator[](const key_type& x);
    mapped_type& operator[](key_type&& x);
    mapped_type&       at(const key_type& x);
    const mapped_type& at(const key_type& x) const;
 
    // modifiers
    pair<iterator, bool> insert(const value_type& x);
    pair<iterator, bool> insert(value_type&& x);
    template<class P> pair<iterator, bool> insert(P&& x);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    template<class P>
      iterator insert(const_iterator position, P&&);
    template<class InputIt>
      void insert(InputIt first, InputIt last);
 
    insert_return_type insert(node_type&& nh);
    iterator           insert(const_iterator hint, node_type&& nh);
 
    iterator  erase(iterator position);
    iterator  erase(const_iterator position);
    size_type erase(const key_type& x);
    iterator  erase(const_iterator first, const_iterator last);
    void      swap(map&)
      (allocator_traits<Allocator>::is_always_equal::value &&
               is_nothrow_swappable_v<Compare>);
    void      clear() ;
 
    // observers
    key_compare key_comp() const;
    value_compare value_comp() const;
 
    // map operations
    iterator       find(const key_type& x);
    const_iterator find(const key_type& x) const;
    template<class K> iterator       find(const K& x);
    template<class K> const_iterator find(const K& x) const;
 
    size_type      count(const key_type& x) const;
    template<class K> size_type count(const K& x) const;
 
    bool           contains(const key_type& x) const;
    template<class K> bool contains(const K& x) const;
 
    iterator       lower_bound(const key_type& x);
    const_iterator lower_bound(const key_type& x) const;
    template<class K> iterator       lower_bound(const K& x);
    template<class K> const_iterator lower_bound(const K& x) const;
 
    iterator       upper_bound(const key_type& x);
    const_iterator upper_bound(const key_type& x) const;
    template<class K> iterator       upper_bound(const K& x);
    template<class K> const_iterator upper_bound(const K& x) const;
 
    pair<iterator, iterator>               equal_range(const key_type& x);
    pair<const_iterator, const_iterator>   equal_range(const key_type& x) const;
    template<class K>
      pair<iterator, iterator>             equal_range(const K& x);
    template<class K>
      pair<const_iterator, const_iterator> equal_range(const K& x) const;
  };

  // swap
  template<class Key, class T, class Compare, class Allocator>
    void swap(map<Key, T, Compare, Allocator>& x,
              map<Key, T, Compare, Allocator>& y)
      ((x.swap(y)));

}  // namespace ft