#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "algorithm_equal.hpp"

int main() {
  std::vector<int> v;
  std::vector<int> v2;

  std::srand(0);

  for (int i = 0; i < 42; i++) {  
    int val = std::rand() % 42;
    v.push_back(val);
    v2.push_back(val);
  }

  std::cout << std::boolalpha;

  std::cout << "ft::\n";
  std::cout << ft::equal(v.begin(), v.end(), v2.begin()) << '\n';
  std::cout << ft::equal(v.begin() + 5, v.end(), v2.begin()) << '\n';
  std::cout << ft::equal(v.begin() + 44, v.end(), v2.begin()) << '\n';
  std::cout << ft::equal(v.begin(), v.end() + 1, v2.begin() + 5) << '\n';

  std::cout << std::endl;

  std::cout << "std::\n";
  std::cout << std::equal(v.begin(), v.end(), v2.begin()) << '\n';
  std::cout << std::equal(v.begin() + 5, v.begin() + 3, v2.begin()) << '\n';
  std::cout << std::equal(v.begin() + 44, v.begin() + 3, v2.begin()) << '\n';
  std::cout << std::equal(v.begin(), v.end() + 1, v2.begin() + 5) << '\n';
}