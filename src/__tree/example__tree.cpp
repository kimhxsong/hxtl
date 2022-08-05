#include <iostream>
#include <vector>

#include "tree.hpp"

void test() {
  ft::hx_tree<char> mytree;
  std::vector<char> arr = {'F','B','G','A','D','I','C','E','H'};

  for (size_t i = 0; i < arr.size(); i++) {
    mytree.insert(arr[i]);
  }
  std::cout << "pre-order: "; 
  mytree.printPreOrder(mytree.root());
  std::cout << std::endl;

  std::cout << "in-order: ";
  mytree.printInOrder(mytree.root());
  std::cout << std::endl;

  std::cout << "post-order: ";
  mytree.printPostOrder(mytree.root());
  std::cout << std::endl;

  for (int i = 0; i < arr.size(); i++) {
    mytree.erase(mytree.root());
  }
}

int main() {
  test();
  system("leaks a.out");
}