#ifndef TREE_TPP_
#define TREE_TPP_

#ifndef TREE_HPP_
#error
#endif

#include "__tree.hpp"

namespace ft
{

template <typename T> __tree_node<T>::__tree_node(const value_type& value)
    : parent_(0), right_(0), left_(0), value_(value)
{
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__
            << std::endl;
}

template <typename T> __tree_node<T>::~__tree_node()
{
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__
            << std::endl;
}

template <typename T> void __tree_node<T>::set_parent(node_pointer parent)
{
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__
            << std::endl;
  parent_ = parent;
}

template <class T, class Compare, class Allocator>
__tree<T, Compare, Allocator>::__tree(const value_compare& comp,
                                      const allocator_type& alloc)
    : alloc_(alloc),
      comp_(comp),
      begin_node_(value_type()),
      end_node_(value_type()),
      root_(0),
      size_(0)
{}

template <class T, class Compare, class Allocator>
__tree<T, Compare, Allocator>::~__tree()
{
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__
            << std::endl;
  clear();
}

// operator= <-- TODO

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::begin()
{
  return iterator(tree_min(end_node_.left_));
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::const_iterator
__tree<T, Compare, Allocator>::begin() const
{
  return const_iterator(&begin_node_);
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::end()
{
  return iterator(&end_node_);
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::const_iterator
__tree<T, Compare, Allocator>::end() const
{
  return const_iterator(&end_node_);
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::reverse_iterator
__tree<T, Compare, Allocator>::rbegin()
{
  return reverse_iterator(this->end());
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::const_reverse_iterator
__tree<T, Compare, Allocator>::rbegin() const
{
  return const_reverse_iteartor(this->end());
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::reverse_iterator
__tree<T, Compare, Allocator>::rend()
{
  return reverse_iterator(this->begin());
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::const_reverse_iterator
__tree<T, Compare, Allocator>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class T, class Compare, class Allocator>
void __tree<T, Compare, Allocator>::insert(const value_type& value)
{
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__
            << std::endl;
  if (!root_)
  {
    root_ = alloc_.allocate(1);
    alloc_.construct(root_, value);
    root_->parent_ = &end_node_;
    end_node_.left_ = root_;
    // begin_node.p = root_;`
    size_++;
    return;
  }

  node_pointer current = root_;
  while (current)
  {
    if (current->value_ == value)
    {
      std::cout << "중복!\n";
      return;
    }

    if (comp_(current->value_, value) != false)
    {
      if (!current->right_)
      {
        current->right_ = alloc_.allocate(1);  // To Fix
        alloc_.construct(current->right_, value);
        current->right_->parent_ = current;
        return;
      }
      current = current->right_;
    }
    else
    {
      if (!current->left_)
      {
        current->left_ = alloc_.allocate(1);  // TO Fix
        alloc_.construct(current->left_, value);
        current->left_->parent_ = current;
        return;
      }
      current = current->left_;
    }
  }
}

template <class T, class Compare, class Allocator>
pair<typename __tree<T, Compare, Allocator>::iterator, bool>
__tree<T, Compare, Allocator>::insert(const value_type& val)
{
  return ft::make_pair(this->begin(), false);
}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::insert(iterator position, const value_type& val)
{
  return this->begin();
}

template <class T, class Compare, class Allocator>
template <class InputIterator> void
__tree<T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{}

template <class T, class Compare, class Allocator>
void __tree<T, Compare, Allocator>::erase(iterator position)
{}

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::size_type
__tree<T, Compare, Allocator>::erase(const value_type& val)
{
  return 0;
}
template <class T, class Compare, class Allocator>
void __tree<T, Compare, Allocator>::erase(iterator first, iterator last)
{}

template <class T, class Compare, class Allocator>
void __tree<T, Compare, Allocator>::clear_recursive(node_pointer np)
{
  if (!np)
    return;
  clear_recursive(np->left_);
  clear_recursive(np->right_);
  alloc_.destroy(np);
  alloc_.deallocate(np, 1);
}

template <class T, class Compare, class Allocator>
void __tree<T, Compare, Allocator>::clear()
{
  std::cout << calls++ << ": " << __func__ << ", line: " << __LINE__
            << std::endl;
  clear_recursive(root_);
}

// 복사생성자를 구현해야 처리할 수 있는 메소드.
// template <class T, class Compare, class Allocator>
// void
// __tree<T, Compare, Allocator>>::swap(__tree& other) {
//   __tree<T, Compare, Allocator> tmp = *other;
//   other = *this;
//   *this = tmp;
//   return *this;
// }

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::key_compare
__tree<T, Compare, Allocator>::key_comp() const
{
  return this->comp_;
}
template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::value_compare
__tree<T, Compare, Allocator>::value_comp() const
{
  return this->comp_;
}
// template <class T, class Compare, class Allocator>
// typename __tree<T, Compare, Allocator>::iterator
//  __tree<T, Compare, Allocator>::find(const value_type& val) const
// {
//   return this->end();
// }
// template <class T, class Compare, class Allocator>
// typename __tree<T, Compare, Allocator>::size_type
//  __tree<T, Compare, Allocator>::count(const value_type& val) const
// {
//   return 0;
// }
// template <class T, class Compare, class Allocator>
// typename __tree<T, Compare, Allocator>::iterator
//  __tree<T, Compare, Allocator>::lower_bound(const value_type& val) const
// {
//   return this->begin();
// }
// template <class T, class Compare, class Allocator>
// typename __tree<T, Compare, Allocator>::iterator
//  __tree<T, Compare, Allocator>::upper_bound(const value_type& val) const
// {
//   return this->begin();
// }

template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::find(const value_type& val)
{
  return this->end();
}
template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::size_type
__tree<T, Compare, Allocator>::count(const value_type& val)
{
  return 0;
}
template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::lower_bound(const value_type& val)
{
  return this->begin();
}
template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::iterator
__tree<T, Compare, Allocator>::upper_bound(const value_type& val)
{
  return this->begin();
}
template <class T, class Compare, class Allocator>
typename __tree<T, Compare, Allocator>::allocator_type
__tree<T, Compare, Allocator>::get_allocator()
{
  return this->alloc_;
}
template <class T, class Compare, class Allocator>
pair<typename __tree<T, Compare, Allocator>::iterator,
     typename __tree<T, Compare, Allocator>::iterator>
__tree<T, Compare, Allocator>::equal_range(const value_type& val)
// __tree<T, Compare, Allocator>::equal_range(const value_type& val) const
{
  return make_pair(this->begin(), this->end());
}

}  // namespace ft

// 왜  오류?
// template<typename T, typename NodePtr, typename DiffType>
// bool
// operator==(const ft::__tree_iterator<T, NodePtr, DiffType>& lhs, const
// ft::__tree_iterator<T, NodePtr, DiffType>& rhs) {
//   return &*lhs == &*rhs;
// }

// template<typename T, typename NodePtr, typename DiffType>
// bool
// operator!=(const ft::__tree_iterator<T, NodePtr, DiffType>& lhs, const
// ft::__tree_iterator<T, NodePtr, DiffType>& rhs) {
//   return !(lhs == rhs);
// }

#endif  // TREE_TPP_