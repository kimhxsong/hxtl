#include "hx_tree.hpp"

#include <functional>
#include <iostream>
#include <map>
#include <tuple>
#include <utility>

#include "gtest/gtest.h"

TEST(tree_constructor, default_constructor) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;      // 9:37
  ft::hx_tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37
}

TEST(tree_insert, default_constructor) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;      // 9:37
  ft::hx_tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }
  for (int i = 21; i >= 0; i--) {
    mytree2.insert(i);
  }
}

TEST(tree_erase, default_constructor) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;      // 9:37
  ft::hx_tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }
  for (int i = 21; i >= 0; i--) {
    mytree2.insert(i);
  }
}

TEST(tree_node, default_constructor) {
  // ft::hx_node<int> node; //  기본생성자 정의하지 않았음
  ft::hx_node<int> node2(21);
  ft::hx_node<int> node3(42);
  node3.set_parent(&node2);
  std::cout << node2.value << std::endl;
  std::cout << node3.value << std::endl;
  std::cout << node3.parent->value << std::endl;
}

TEST(tree_iterator, default_constructor) {
  ft::hxiterator<int, ft::hx_node<int>*> it;
  ft::hx_tree<int, std::less<int>, std::allocator<int> >::iterator it2;
  // std::map<int, int>::iterator it3;
  // it3++;
  // it++;
  // it2++;
}

TEST(tree_node_next_prev, test) {
  // ft::hx_node<int> node; //  기본생성자 정의하지 않았음
  ft::hx_node<int> node2(21);
  ft::hx_node<int> node3(42);
  node2.right = &node3;
  node3.set_parent(&node2);
  ft::hx_node<int>* np3 = ft::treeNext<ft::hx_node<int>*>(&node2);
  std::cout << node3.value << std::endl;
  std::cout << np3->value << std::endl;
  ft::hx_node<int>* np2 = ft::treePrev<ft::hx_node<int>*>(np3);
  std::cout << np2->value << std::endl;
}

TEST(tree, test) {
  // ft::hx_node<int> node; //  기본생성자 정의하지 않았음
  ft::hx_node<int> node2(21);
  ft::hx_node<int> node3(42);
  node2.right = &node3;
  node3.set_parent(&node2);
  ft::hx_node<int>* np3 = ft::treeNext<ft::hx_node<int>*>(&node2);
  std::cout << node3.value << std::endl;
  std::cout << np3->value << std::endl;
  ft::hx_node<int>* np2 = ft::treePrev<ft::hx_node<int>*>(np3);
}

TEST(tree_iterators, begin_end) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;      // 9:37
  ft::hx_tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37
  ft::hx_tree<int, std::plus<int>, std::allocator<int> > mytree3;     // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
    mytree2.insert(i);
    mytree3.insert(i);
  }
  ft::hx_tree<int, std::less<int>, std::allocator<int> >::iterator it = mytree.begin();
  ft::hx_tree<int, std::greater<int>, std::allocator<int> >::iterator it2 = mytree2.begin();
  ft::hx_tree<int, std::plus<int>, std::allocator<int> >::iterator it3 = mytree3.begin();
  while (it != mytree.end()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
  while (it2 != mytree2.end()) {
    std::cout << *it2 << " ";
    it2++;
  }
  std::cout << std::endl;
  while (it3 != mytree3.end()) {
    std::cout << *it3 << " ";
    it3++;
  }
  it--;
  --it;
  ++it;
  std::cout << std::endl;

  /*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 0 1
*/
}

TEST(tree_iterators, rbegin_rend) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;      // 9:37
  ft::hx_tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37
  ft::hx_tree<int, std::plus<int>, std::allocator<int> > mytree3;     // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
    mytree2.insert(i);
    mytree3.insert(i);
  }
  ft::hx_tree<int, std::less<int>, std::allocator<int> >::reverse_iterator it = mytree.rbegin();
  ft::hx_tree<int, std::greater<int>, std::allocator<int> >::reverse_iterator it2 =
      mytree2.rbegin();
  ft::hx_tree<int, std::plus<int>, std::allocator<int> >::reverse_iterator it3 = mytree3.rbegin();
  while (it != mytree.rend()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
  while (it2 != mytree2.rend()) {
    std::cout << *it2 << " ";
    it2++;
  }
  std::cout << std::endl;
  while (it3 != mytree3.rend()) {
    std::cout << *it3 << " ";
    it3++;
  }
  it--;
  --it;
  ++it;
  std::cout << std::endl;

  /*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 0 1
*/
}

TEST(tree_iterators, bidirectional_iterator_test) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;
  ft::hx_tree<std::string, std::less<std::string>, std::allocator<int> > mytree2;

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }

  mytree2.insert("Hello");

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  ft::hx_tree<int, std::less<int>, std::allocator<int> >::iterator it = mytree.begin();
  ft::hx_tree<int, std::greater<int>, std::allocator<int> >::iterator it2(it);
  ft::hx_tree<int, std::plus<int>, std::allocator<int> >::iterator it3;
  it3 = it2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(it2, it3);
  EXPECT_EQ(it2 != mytree.end(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ(*it2 == 0, true);
  EXPECT_EQ(mytree2.begin()->size() == std::string("Hello").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
  *it2 = -1;
  EXPECT_EQ(*it2 == -1, true);
  *it2 = 0;

  // Can be incremented(if in a dereferenceable state)
  // .The result is either also dereferenceable or
  // a past - the - end iterator.Two iterators that compare equal,
  // keep comparing equal after being both increased.
  ++it;
  it++;
  EXPECT_EQ(*it++ == 2, true);

  --it;
  it--;
  EXPECT_EQ(*it-- == 1, true);
}

// TODO
TEST(tree_iterators, convert_iterator_to_const_iterator) {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }

  typedef ft::hx_tree<int, std::less<int>, std::allocator<int> >::iterator iterator;
  typedef ft::hx_tree<int, std::less<int>, std::allocator<int> >::const_iterator const_iterator;
  iterator it = mytree.begin();
  const_iterator cit;
  const_iterator cit2(cit);
  const_iterator cit3;

  // convert iterator to const_iterator
  const_iterator cit4(it);
  const_iterator cit5;
  // iterator it2(cit);  // Does Not Compile.
}