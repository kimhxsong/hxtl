#ifndef MAP_TPP_
#define MAP_TPP_

#ifndef MAP_HPP_
#error  error
#endif  // MAP_HPP_


template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc);  // empty (1)
  
template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc);  // range (2)	

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map (const map& x);  // copy (3)

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::~map();

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator=(const map& x);

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin();
  
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin() const;

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end();
  
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::end() const;

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin();

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin() const;

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rend();

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rend() const;

template <class Key, class T, class Compare, class Alloc>
bool map<Key, T, Compare, Alloc>::empty() const;

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::size() const;

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::max_size() const;

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::operator[](const key_type& k);

  pair<iterator,bool> insert (const value_type& val);  // single element (1)	
  iterator insert (iterator position, const value_type& val);  // with hint (2)	
  template <class InputIterator>
  void insert (InputIterator first, InputIterator last);  // range (3)	
  void erase (iterator position);
  size_type erase(const key_type& k);
  void erase(iterator first, iterator last);
  void swap (map& x);
  void clear();

  iterator find(const key_type& k);
  const_iterator find(const key_type& k) const;

  size_type count(const key_type& k) const;

  key_compare key_comp() const;
  value_compare value_comp() const;

  iterator lower_bound(const key_type& k);
  const_iterator lower_bound(const key_type& k) const;

  iterator upper_bound(const key_type& k);
  const_iterator upper_bound(const key_type& k) const;

  pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
  pair<iterator,iterator> equal_range(const key_type& k);

  allocator_type get_allocator() const;
};


#endif  // MAP_TPP_