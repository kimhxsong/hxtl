#include <iostream>
#include <string>
// #include <utility>

#include "utility_pair.hpp"

int main() {
  std::cout << "std" << std::endl;

  std::pair<std::string, int> emptry_pr;
  std::pair<std::string, int> pr("count", 42);
  std::pair<std::string, int> cpr(pr);

  std::cout << emptry_pr.first << ", " << emptry_pr.second << std::endl;

  std::cout << pr.first << ", " << pr.second << std::endl;
  std::cout << cpr.first << ", " << cpr.second << std::endl;

  std::cout << &pr.first << ", " << &pr.second << std::endl;
  std::cout << &cpr.first << ", " << &cpr.second << std::endl;

  std::cout << "ft" << std::endl;

  ft::pair<std::string, int> emptry_pr2;
  ft::pair<std::string, int> pr2("count", 42);
  ft::pair<std::string, int> cpr2(pr2);

  std::cout << emptry_pr2.first << ", " << emptry_pr2.second << std::endl;

  std::cout << pr2.first << ", " << pr2.second << std::endl;
  std::cout << cpr2.first << ", " << cpr2.second << std::endl;

  std::cout << &pr2.first << ", " << &pr2.second << std::endl;
  std::cout << &cpr2.first << ", " << &cpr2.second << std::endl;
}
