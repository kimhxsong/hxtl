#include "hxtree.hpp"

#include <iostream>

int main()
{
  ft::hxtree<int, std::less<int>, std::allocator<int> > mytree;      // 9:37
  ft::hxtree<int, std::greater<int>, std::allocator<int> > mytree2;  // 9:37

  for (int i = 0; i < 21; i++)
  {
    mytree.insert(i);
  }
  for (int i = 21; i >= 0; i--)
  {
    mytree2.insert(i);
  }
}