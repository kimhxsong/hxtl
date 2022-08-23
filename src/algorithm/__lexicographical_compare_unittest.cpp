#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <string>

#include <map>

#include "gtest/gtest.h"

#if 0
  namespace ft = std;
#else
#include "__lexicographical_compare.hpp"
#endif

TEST(equal, equality__1)
{
  std::map<int, int> __std__map;
  std::srand(0);
  for (int i = 0; i < 1000; i++)
  {
    __std__map[i] = rand();
  }

  std::map<int, int> __std__map2(__std__map);
  EXPECT_EQ(
      std::equal(__std__map.begin(), __std__map.end(), __std__map2.begin()),
      true);
  EXPECT_EQ(ft::lexicographical_compare(__std__map.begin(), __std__map.end(),
                                        __std__map2.begin(), __std__map2.end()),
            false);
  EXPECT_EQ(
      std::lexicographical_compare(__std__map.begin(), __std__map.end(),
                                   __std__map2.begin(), __std__map2.end()),
      ft::lexicographical_compare(__std__map.begin(), __std__map.end(),
                                  __std__map2.begin(), __std__map2.end()));

  for (int i = 0; i < 1000; i++)
  {
    __std__map2[i] += 1;
  }

  EXPECT_EQ(
      std::equal(__std__map.begin(), __std__map.end(), __std__map2.begin()),
      false);
  EXPECT_EQ(ft::lexicographical_compare(__std__map.begin(), __std__map.end(),
                                        __std__map2.begin(), __std__map2.end()),
            true);
  EXPECT_EQ(
      std::lexicographical_compare(__std__map.begin(), __std__map.end(),
                                   __std__map2.begin(), __std__map2.end()),
      ft::lexicographical_compare(__std__map.begin(), __std__map.end(),
                                  __std__map2.begin(), __std__map2.end()));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
