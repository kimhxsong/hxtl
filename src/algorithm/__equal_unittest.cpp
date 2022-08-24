#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#if 0
  namespace ft = std;
#else
#include "__equal.hpp"
#endif

TEST(equal, equality__1) {
  std::vector<int> __std__vec;

  std::srand(0);
  for (int i = 0; i < 100; i++) {
    __std__vec.push_back(std::rand() % 100);
  }
  std::sort(__std__vec.begin(), __std__vec.end());

  std::list<int> __std__list(__std__vec.begin(), __std__vec.end());
  std::multiset<int> __std__multiset(__std__vec.begin(), __std__vec.end());

  EXPECT_EQ(ft::equal(__std__list.begin(), __std__list.end(), __std__vec.begin()), true);
  EXPECT_EQ(ft::equal(__std__vec.begin(), __std__vec.end(), __std__list.begin()), true);
  EXPECT_EQ(ft::equal(__std__multiset.begin(), __std__multiset.end(), __std__vec.begin()), true);
  EXPECT_EQ(ft::equal(__std__vec.begin(), __std__vec.end(), __std__multiset.begin()), true);
}

TEST(equal, predicate__2) {
  std::vector<int> __std__vec;

  std::srand(0);
  for (int i = 0; i < 100; i++) {
    __std__vec.push_back(std::rand() % 100);
  }
  std::sort(__std__vec.begin(), __std__vec.end());

  std::list<int> __std__list(__std__vec.begin(), __std__vec.end());
  std::multiset<int> __std__multiset(__std__vec.begin(), __std__vec.end());

  EXPECT_EQ(
      ft::equal(__std__list.begin(), __std__list.end(), __std__vec.begin(), std::equal_to<int>()),
      true);
  EXPECT_EQ(
      ft::equal(__std__vec.begin(), __std__vec.end(), __std__list.begin(), std::equal_to<int>()),
      true);
  EXPECT_EQ(ft::equal(__std__multiset.begin(), __std__multiset.end(), __std__vec.begin(),
                      std::equal_to<int>()),
            true);
  EXPECT_EQ(ft::equal(__std__vec.begin(), __std__vec.end(), __std__multiset.begin(),
                      std::equal_to<int>()),
            true);

  EXPECT_EQ(ft::equal(__std__list.begin(), __std__list.end(), __std__vec.begin(),
                      std::not_equal_to<int>()),
            false);
  EXPECT_EQ(ft::equal(__std__vec.begin(), __std__vec.end(), __std__list.begin(),
                      std::not_equal_to<int>()),
            false);
  EXPECT_EQ(ft::equal(__std__multiset.begin(), __std__multiset.end(), __std__vec.begin(),
                      std::not_equal_to<int>()),
            false);
  EXPECT_EQ(ft::equal(__std__vec.begin(), __std__vec.end(), __std__multiset.begin(),
                      std::not_equal_to<int>()),
            false);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
