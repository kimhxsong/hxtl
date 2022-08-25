#include <iostream>

#include "hx_tree.hpp"

int main() {
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree;   // 9:37
  ft::hx_tree<int, std::less<int>, std::allocator<int> > mytree2;  // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }
  mytree2 = mytree;
}