#ifndef TREE_ITERATOR_TPP_
#define TREE_ITERATOR_TPP_

#ifndef TREE_ITERATOR_HPP_
#error
#endif  // TREE_ITERATOR_HPP_

#include "../iterator/iterator.hpp"
#include "__tree_iterator.hpp"

namespace ft
{

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr>::__tree_iterator()
{}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr>::__tree_iterator(const __tree_iterator& other)
    : ptr_(other.ptr_)
{}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr>::__tree_iterator(
    const __tree_iterator<value_type, ft::__tree<value_type>::node_pointer>&
        other)
    : ptr_(other.ptr_)
{}

template <typename T, typename NodePtr> __tree_iterator<T, NodePtr>&
__tree_iterator<T, NodePtr>::operator=(const __tree_iterator& other)
{
  if (this != &other)
  {
    this->ptr_ = other.ptr_;
  }
  return *this;
}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr>::~__tree_iterator()
{}

template <typename T, typename NodePtr>
typename __tree_iterator<T, NodePtr>::reference
__tree_iterator<T, NodePtr>::operator*()
{
  return ptr_->value_;
}

template <typename T, typename NodePtr>
typename __tree_iterator<T, NodePtr>::const_reference
__tree_iterator<T, NodePtr>::operator*() const
{
  return ptr_->value_;
}

template <typename T, typename NodePtr>
typename __tree_iterator<T, NodePtr>::pointer
__tree_iterator<T, NodePtr>::operator->()
{
  return &(ptr_->value_);
}

template <typename T, typename NodePtr>
typename __tree_iterator<T, NodePtr>::const_pointer
__tree_iterator<T, NodePtr>::operator->() const
{
  return &(ptr_->value_);
}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr>& __tree_iterator<T, NodePtr>::operator++()
{
  ptr_ = tree_next<NodePtr>(ptr_);
  return *this;
}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr> __tree_iterator<T, NodePtr>::operator++(int)
{
  __tree_iterator tmp(*this);
  ++(*this);
  return tmp;
}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr>& __tree_iterator<T, NodePtr>::operator--()
{
  ptr_ = tree_prev<NodePtr>(ptr_);
  return *this;
}

template <typename T, typename NodePtr>
__tree_iterator<T, NodePtr> __tree_iterator<T, NodePtr>::operator--(int)
{
  __tree_iterator tmp(*this);
  --(*this);
  return tmp;
}

// template <class T>
// std::ostream &operator<<(const std::ostream &os, const __tree_iterator<T>
// &it) {
//   os << *ptr_;
//   return *os;
// }

}  // namespace ft

#endif  // TREE_ITERATOR_TPP_
