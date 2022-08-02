#include "tree.hpp"
#include "map.hpp"
#include "functional.hpp"
#include <memory>

int main() {
  // {
  //   ft::ft_tree_node<int> node1(0);
  // }
  // ft::ft_tree<int> mytree;
  ft::ft_tree<int, ft::less<int>, std::allocator<int> > mytree;
  mytree.insert(1);
  mytree.insert(2);
  mytree.insert(3);
  mytree.insert(4);

  ft::ft_tree<int, ft::less<int>, std::allocator<int> >::iterator tit;
  ft::map<char, int> mymap;
  ft::map<char, int>::iterator mit; 
}