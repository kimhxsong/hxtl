#include <iostream>

#include "tree.hpp"
#include <map>
#include <utility>
#include "gtest/gtest.h"
  #include <map>

#include <functional>

#include <__tree>

TEST(tree_constructor, default_constructor) {
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree;  // 9:37
  ft::__tree<int, std::greater<int>, std::allocator<int> > mytree2; // 9:37
}

TEST(tree_insert, default_constructor) {
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree;  // 9:37
  ft::__tree<int, std::greater<int>, std::allocator<int> > mytree2; // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }
  for (int i = 21; i >= 0; i--) {
    mytree2.insert(i);
  }
}

TEST(tree_erase, default_constructor) {
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree;  // 9:37
  ft::__tree<int, std::greater<int>, std::allocator<int> > mytree2; // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }
  for (int i = 21; i >= 0; i--) {
    mytree2.insert(i);
  }
}

TEST(tree_node, default_constructor) {
  // ft::__tree_node<int> node; //  기본생성자 정의하지 않았음
  ft::__tree_node<int> node2(21);
  ft::__tree_node<int> node3(42);
  node3.set_parent(&node2);
  std::cout << node2.value_ << std::endl;
  std::cout << node3.value_ << std::endl;
  std::cout << node3.parent_->value_ << std::endl;
}

TEST(tree_iterator, default_constructor) {
  ft::__tree_iterator<int, ft::__tree_node<int>::pointer, ptrdiff_t> it;
  ft::__tree<int, std::less<int>, std::allocator<int> >::iterator it2;
  // it++;
  // it2++;
}

TEST(tree_node_next_prev, test) {
  // ft::__tree_node<int> node; //  기본생성자 정의하지 않았음
  ft::__tree_node<int> node2(21);
  ft::__tree_node<int> node3(42);
  node2.right_ = &node3;
  node3.set_parent(&node2);
  ft::__tree_node<int>* np3 = ft::tree_next<ft::__tree_node<int>::pointer>(&node2);
  std::cout << node3.value_ << std::endl;
  std::cout << np3->value_ << std::endl;
  ft::__tree_node<int>* np2 = ft::tree_prev<ft::__tree_node<int>::pointer>(np3);
  std::cout << np2->value_ << std::endl;
}

TEST(tree, test) {
  // ft::__tree_node<int> node; //  기본생성자 정의하지 않았음
  ft::__tree_node<int> node2(21);
  ft::__tree_node<int> node3(42);
  node2.right_ = &node3;
  node3.set_parent(&node2);
  ft::__tree_node<int>* np3 = ft::tree_next<ft::__tree_node<int>::pointer>(&node2);
  std::cout << node3.value_ << std::endl;
  std::cout << np3->value_ << std::endl;
  ft::__tree_node<int>* np2 = ft::tree_prev<ft::__tree_node<int>::pointer>(np3);
}

TEST(tree_iterators, begin_end) {
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree;  // 9:37
  ft::__tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37
  ft::__tree<int, std::plus<int>, std::allocator<int> > mytree3;  // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
    mytree2.insert(i);
    mytree3.insert(i);
  }
  ft::__tree<int, std::less<int>, std::allocator<int> >::iterator it = mytree.begin();
  ft::__tree<int, std::greater<int>, std::allocator<int> >::iterator it2 = mytree2.begin();
  ft::__tree<int, std::plus<int>, std::allocator<int> >::iterator it3 = mytree3.begin();
  while (it != mytree.end()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
  while (it2 != mytree2.end()) {
    std::cout << *it2 << " ";
    it2++;
  }
  // std::cout << std::endl;
  // while (it3 != mytree3.end()) {
  //   std::cout << *it3 << " ";
  //   it3++;
  // }
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
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree;  // 9:37
  ft::__tree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37
  ft::__tree<int, std::plus<int>, std::allocator<int> > mytree3;  // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
    mytree2.insert(i);
    mytree3.insert(i);
  }
  ft::__tree<int, std::less<int>, std::allocator<int> >::reverse_iterator it = mytree.rbegin();
  ft::__tree<int, std::greater<int>, std::allocator<int> >::reverse_iterator it2 = mytree2.rbegin();
  ft::__tree<int, std::plus<int>, std::allocator<int> >::reverse_iterator it3 = mytree3.rbegin();
  while (it != mytree.rend()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
  while (it2 != mytree2.rend()) {
    std::cout << *it2 << " ";
    it2++;
  }
  // std::cout << std::endl;
  // while (it3 != mytree3.end()) {
  //   std::cout << *it3 << " ";
  //   it3++;
  // }
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

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}