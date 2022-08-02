#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <iterator>

#include "functional.hpp"
#include "pair.hpp"
#include "iterator.hpp"
#include "tree.hpp"
#include <map>

// class _LIBCPP_TEMPLATE_VIS __tree_iterator
// {
//     typedef __tree_node_types<_NodePtr>                     _NodeTypes;
//     typedef _NodePtr                                        __node_pointer;
//     typedef typename _NodeTypes::__node_base_pointer        __node_base_pointer;
//     typedef typename _NodeTypes::__end_node_pointer         __end_node_pointer;
//     typedef typename _NodeTypes::__iter_pointer             __iter_pointer;
//     typedef pointer_traits<__node_pointer> __pointer_traits;

//     __iter_pointer __ptr_;

// public:
//     typedef bidirectional_iterator_tag                     iterator_category;
//     typedef _Tp                                            value_type;
//     typedef _DiffType                                      difference_type;
//     typedef value_type&                                    reference;
//     typedef typename _NodeTypes::__node_value_type_pointer pointer;

//     _LIBCPP_INLINE_VISIBILITY __tree_iterator() _NOEXCEPT
// #if _LIBCPP_STD_VER > 11
//     : __ptr_(nullptr)
// #endif
//     {}

//     _LIBCPP_INLINE_VISIBILITY reference operator*() const
//         {return __get_np()->__value_;}
//     _LIBCPP_INLINE_VISIBILITY pointer operator->() const
//         {return pointer_traits<pointer>::pointer_to(__get_np()->__value_);}

//     _LIBCPP_INLINE_VISIBILITY
//     __tree_iterator& operator++() {
//       __ptr_ = static_cast<__iter_pointer>(
//           __tree_next_iter<__end_node_pointer>(static_cast<__node_base_pointer>(__ptr_)));
//       return *this;
//     }
//     _LIBCPP_INLINE_VISIBILITY
//     __tree_iterator operator++(int)
//         {__tree_iterator __t(*this); ++(*this); return __t;}

//     _LIBCPP_INLINE_VISIBILITY
//     __tree_iterator& operator--() {
//       __ptr_ = static_cast<__iter_pointer>(__tree_prev_iter<__node_base_pointer>(
//           static_cast<__end_node_pointer>(__ptr_)));
//       return *this;
//     }
//     _LIBCPP_INLINE_VISIBILITY
//     __tree_iterator operator--(int)
//         {__tree_iterator __t(*this); --(*this); return __t;}

//     friend _LIBCPP_INLINE_VISIBILITY
//         bool operator==(const __tree_iterator& __x, const __tree_iterator& __y)
//         {return __x.__ptr_ == __y.__ptr_;}
//     friend _LIBCPP_INLINE_VISIBILITY
//         bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
//         {return !(__x == __y);}

// private:
//     _LIBCPP_INLINE_VISIBILITY
//     explicit __tree_iterator(__node_pointer __p) _NOEXCEPT : __ptr_(__p) {}
//     _LIBCPP_INLINE_VISIBILITY
//     explicit __tree_iterator(__end_node_pointer __p) _NOEXCEPT : __ptr_(__p) {}
//     _LIBCPP_INLINE_VISIBILITY
//     __node_pointer __get_np() const { return static_cast<__node_pointer>(__ptr_); }
//     template <class, class, class> friend class __tree;
//     template <class, class, class> friend class _LIBCPP_TEMPLATE_VIS __tree_const_iterator;
//     template <class> friend class _LIBCPP_TEMPLATE_VIS __map_iterator;
//     template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS map;
//     template <class, class, class, class> friend class _LIBCPP_TEMPLATE_VIS multimap;
//     template <class, class, class> friend class _LIBCPP_TEMPLATE_VIS set;
//     template <class, class, class> friend class _LIBCPP_TEMPLATE_VIS multiset;
// };


namespace ft {

template <class TreeIterator>
class map_iterator {
    typedef typename TreeIterator::NodeTypes NodeTypes;
    
    TreeIterator it_;

public:
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef typename NodeTypes::map_value_type value_type;
    typedef typename TreeIterator::difference_type difference_type;
    typedef value_type& reference;
    typedef typename NodeTypes::map_value_type_pointer  pointer;

    map_iterator() {}
    map_iterator(TreeIterator it) : it_(it) {}

    reference operator*() const {
      return it_->get_value();
    }

    pointer operator->() const {
      return &(it_->get_value());
    }

    map_iterator& operator++() {
      ++it_;
      return *this;
    }

    map_iterator operator++(int) {
        map_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    map_iterator& operator--() {
      --it_;
      return *this;
    }

    map_iterator operator--(int) {
        map_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) {
      return lhs.it_ == rhs.it_;
    }

    friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs) {
      return lhs.it_ != rhs.it_;
    }

    template <class, class, class, class> friend class map;
    template <class> friend class map_const_iterator;
};

// template <class TreeIterator>
// class map_const_iterator {
//     typedef typename TreeIterator::NodeTypes NodeTypes;
    
//     TreeIterator it_;

// public:
//     typedef std::bidirectional_iterator_tag iterator_category;
//     typedef typename NodeTypes::map_value_type value_type;
//     typedef typename TreeIterator::difference_type difference_type;
//     typedef value_type& reference;
//     typedef typename NodeTypes::map_value_type_pointer  pointer;

//     map_const_iterator() {}
//     map_const_iterator(TreeIterator it) : it_(it) {}
//     // map_const_iterator( it) : it_(it) {} non_const_iterator 받을 수 있도록.

//     reference operator*() const {
//       return it_->get_value();
//     }

//     pointer operator->() const {
//       return &(it_->get_value());
//     }

//     map_const_iterator& operator++() {
//       ++it_;
//       return *this;
//     }

//     map_const_iterator operator++(int) {
//         map_const_iterator tmp(*this);
//         ++(*this);
//         return tmp;
//     }

//     map_iterator& operator--() {
//       --it_;
//       return *this;
//     }

//     map_iterator operator--(int) {
//         map_iterator tmp(*this);
//         --(*this);
//         return tmp;
//     }

//     friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) {
//       return lhs.it_ == rhs.it_;
//     }

//     friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs) {
//       return lhs.it_ != rhs.it_;
//     }

//     template <class, class, class, class> friend class map;
// };


template <class Key, class T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<pair<const Key,T> > >
class map {
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const key_type,mapped_type> value_type;
  typedef ft::less<key_type> key_compare;
  // typedef typename Nested function class to compare elements	see value_comp value_compare;
  typedef std::allocator<value_type> allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef __tree_iterator<value_type, __tree_node<value_type>, di> iterator;
  // typedef typename const_iterator<iterator> const_iterator;
  // typedef typename reverse_iterator<iterator> reverse_iterator;
  // typedef typename reverse_iterator<const_iterator> const_reverse_iterator;
  // typedef typename iterator_traits<iterator>::difference_type difference_type;
  typedef typename allocator_type::size_type size_type;
  // typedef ft::tree_node<value_type> node_type;
};


}  // namespace ft

#endif  // MAP_HPP_