#ifndef MAP_HPP_
#define MAP_HPP_

#include <utility>


template <class Key, class T, class Compare = less<Key>,
          class Allocator = allocator<pair<const Key, Tp> > >
class map {
public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef typename __identity<_Compare>::type key_compare;
    typedef typename __identity<_Allocator>::type allocator_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

    class _LIBCPP_TEMPLATE_VIS value_compare
        : public binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;

        _LIBCPP_INLINE_VISIBILITY value_compare(key_compare c) : comp(c) {}
    public:
        _LIBCPP_INLINE_VISIBILITY
        bool operator()(const value_type& __x, const value_type& __y) const
            {return comp(__x.first, __y.first);}
    };

public:
    typedef typename __alloc_traits::pointer pointer;
    typedef typename __alloc_traits::const_pointer const_pointer;
    typedef typename __alloc_traits::size_type size_type;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef __map_iterator<typename __base::iterator> iterator;
    typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
    typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;

#if _LIBCPP_STD_VER > 14
    typedef __map_node_handle<typename __base::__node, allocator_type> node_type;
    typedef __insert_return_type<iterator, node_type> insert_return_type;
#endif

    template <class _Key2, class _Value2, class _Comp2, class _Alloc2>
        friend class _LIBCPP_TEMPLATE_VIS map;
    template <class _Key2, class _Value2, class _Comp2, class _Alloc2>
        friend class _LIBCPP_TEMPLATE_VIS multimap;
}

/**
template <class Key,
          class T,
          class Compare = less<Key>,
          class Alloc = allocator<pair<const Key,T> > >
class map {
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type:: const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type:: difference_type;

    typedef implementation-defined iterator;
    typedef implementation-defined const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    // typedef unspecified                              node_type;              // C++17
    // typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;     // C++17

  explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());  // empty (1)
  template <class InputIterator>
  map (InputIterator first, InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type());  // range (2)	
  map (const map& x);  // copy (3)

  ~map();

  map& operator= (const map& x);

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  mapped_type& operator[] (const key_type& k);

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
*/

template <class Key,
          class T,
          class Compare = less<Key>,
          class Alloc = allocator<pair<const Key,T> > >
class map
  : ft::tree_node<pair<const Key, T> > {
  typedef Key key_type;
  typedef typename T mapped_type;
  typedef typename pair<const key_type,mapped_type> value_type;
  typedef typename less<key_type> key_compare;
  // typedef typename Nested function class to compare elements	see value_comp value_compare;
  typedef typename allocator<value_type> allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  // typedef typename map_iterator<> iterator;
  // typedef typename map_iterator<> const_iterator;
  typedef typename reverse_iterator<iterator> reverse_iterator;
  typedef typename reverse_iterator<const_iterator> const_reverse_iterator;
  typedef typename iterator_traits<iterator>::difference_type difference_type;
  typedef typename size_t size_type;
  typedef ft::tree_node<value_type> node_type;

  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
    : alloc_(alloc),
      comp_(comp),
      root(0),
      size_(0) {
    //
  }

  template <class InputIterator>
  map(InputIterator first, InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
    : alloc_(alloc),
      comp_(comp),
      root(0),
      size_(0) {
    //
  }

  map(const map& x)
    : alloc_(alloc),
      comp_(comp),
      root(0),
      size_(0) {
    //
  }

  ~map() {
    //
  }

  map& operator=(const map& x) {
    alloc_ = x.allo_;
    comp_ - x.comp_;
    root_ = x.root_;  // 깊은 복사일까? 얕은 복사일까?
    size_ = x.size_;
  }

  iterator begin() {}  // 만들때마다 찾아야 하는건가?
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  bool empty() const {
    return this->size() == 0;
  }

  size_type size() const {
    return size_;
  }

  size_type max_size() const {
    // return std::numeric_limits<
    return;
  }

  // mapped_type& operator[](const key_type& k) {

  // }

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

  allocator_type get_allocator() const{
    return alloc_;
  }

 private:
  allocator_type alloc_;
  key_compare& comp_;
  node_type* root;
  size_type size_;
};

#include "map.tpp"

#endif  // MAP_HPP_