#ifndef TREE_ITERATOR_HPP_
#define TREE_ITERATOR_HPP_

#include <iterator>
#include <ostream>

namespace ft {


// TODO impl tree_node
template <class T>
struct tree_node {
  T data;
  tree_node<T>* left;
  tree_node<T>* right;
}

template <class T>
class tree_iterator
  : public std::iterator<std::bidirectional_iterator_tag, tree_node<T> > {
 public:
  typedef typename tree_iterator<T>::iterator_category iterator_category;
  typedef typename tree_iterator<T>::value_type value_type;
  typedef typename tree_iterator<T>::difference_type difference_type;
  typedef typename tree_iterator<T>::pointer pointer;
  typedef typename tree_iterator<T>::reference reference;

  tree_iterator();
  tree_iterator(pointer p);
  tree_iterator(const tree_iterator<T>& other);

  ~tree_iterator();

  tree_iterator& operator=(const tree_iterator<T>& other);

  tree_iterator& operator++();
  tree_iterator operator++(int);

  bool operator==(const tree_iterator& other);
  bool operator!=(const tree_iterator& other);

  reference operator*();
  pointer operator->();

  tree_iterator& operator--();
  tree_iterator operator--(int);

 private:
  pointer it_;
};

template<class T>
std::ostream& operator<<(const std::ostream& os, const tree_iterator<T>& it);

}  // namespace ft

#endif  // RANDOME_ITERATOR_HPP_
