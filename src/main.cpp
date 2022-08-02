#include "tree.hpp"
#include "map.hpp"
#include "functional.hpp"
#include <memory>

int main() {
  // {
  //   ft::__tree_node<int> node1(0);
  // }
  // ft::__tree<int> mytree;
  ft::__tree<int, ft::less<int>, std::allocator<int> > mytree;
  mytree.insert(1);
  mytree.insert(2);
  mytree.insert(3);
  mytree.insert(4);

  ft::__tree<int, ft::less<int>, std::allocator<int> >::iterator tit;
  ft::map<char, int> mymap;
  ft::map<char, int>::iterator mit; 
}