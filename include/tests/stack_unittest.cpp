
#include <iostream>
#include <iterator>
#include <string>

#include "gtest/gtest.h"

#if 0
#include <stack>
#include <utiliy>
namespace ft = std;
#else
#include "__pair.hpp"
#include "stack.hpp"
#endif


TEST(Stack, constructor)
{
  ft::stack<int> mstk_1;
  ft::stack<ft::pair<char, int> > mstk_2;
}

TEST(Stack, empty)
{
  ft::stack<int> mstk_1;
  ft::stack<ft::pair<char, int> > mstk_2;
  EXPECT_EQ(mstk_1.empty(), true);
  EXPECT_EQ(mstk_2.empty(), true);
}

TEST(Stack, size)
{
  ft::stack<int> mstk_1;
  ft::stack<ft::pair<char, int> > mstk_2;
  EXPECT_EQ(mstk_1.size(), 0);
  EXPECT_EQ(mstk_2.size(), 0);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}