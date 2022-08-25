#include <iostream>
#include <vector>

#include "vector.hpp"

// namespace ft = std;

void printSize(ft::vector<int>& vec) {
  std::cout << std::endl;
  ft::vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    std::cout << *it++ << std::endl;
  }
  std::cout << std::endl;
}
int main(void) {
  ft::vector<int> vct(5);
  ft::vector<int> vct2;

  const int cut = 3;
  for (unsigned long int i = 0; i < vct.size(); ++i) vct[i] = (vct.size() - i) * 7;
  printSize(vct);

  vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
  printSize(vct2);
  vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
  printSize(vct2);
  vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
  printSize(vct2);

  std::cout << "insert return:" << std::endl;

  std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
  printSize(vct2);
  std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
  printSize(vct2);
  std::cout << "----------------------------------------" << std::endl;
  return (0);
}
