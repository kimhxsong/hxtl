#include <iostream>

#include "__tree.hpp"

int main() {
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree;   // 9:37
  ft::__tree<int, std::less<int>, std::allocator<int> > mytree2;  // 9:37

  for (int i = 0; i < 21; i++) {
    mytree.insert(i);
  }
  mytree2 = mytree;
}