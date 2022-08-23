
#include <iostream>
#include <iterator>
#include <string>

#include "gtest/gtest.h"

namespace ft = std;

TEST(Stack, constructor)
{
  std::stack<int> mstk_1;
  std::stack<std::pair<char, int> > mstk_2;
}

TEST(Stack, empty)
{
  std::stack<int> mstk_1;
  std::stack<std::pair<char, int> > mstk_2;
  EXPECT_EQ(mstk_1.empty(), true);
  EXPECT_EQ(mstk_2.empty(), true);
}

TEST(Stack, size)
{
  std::stack<int> mstk_1;
  std::stack<std::pair<char, int> > mstk_2;
  EXPECT_EQ(mstk_1.size(), 0);
  EXPECT_EQ(mstk_2.size(), 0);
}

TEST(ReverseIteratorIterator, reverse_iterator)
{
  std::ReverseIterator<int> vi_1(10);
  vi_1.rbegin();
  vi_1.rend();
}

TEST(ReverseIteratorIterator, convertible_to_const_iterator)
{
  std::ReverseIterator<int>::iterator it;
  std::ReverseIterator<int>::const_iterator cit(it);
}

TEST(ReverseIteratorCapacity, capacity)
{
  std::ReverseIterator<int> vi_1(10);
  vi_1.size();
  vi_1.max_size();
  vi_1.resize(20);
  vi_1.empty();
  vi_1.reserve(40);
}

TEST(ReverseIteratorElementAceess, element_access)
{
  std::ReverseIterator<int> vi_1(10);
  vi_1[0];
  vi_1.at(0);
  vi_1.front();
  vi_1.back();
}

TEST(ReverseIteratorModifiers, assign)
{
  std::ReverseIterator<int> vi_1(10);
  std::ReverseIterator<int> vi_2;
  vi_2.assign(vi_1.begin(), vi_1.end());  // range(1)
  vi_2.assign(20, 5);                     // fill(2)
}

TEST(ReverseIteratorModifiers, push_back)
{
  std::ReverseIterator<int> vi_1;
  vi_1.push_back(10);
}

TEST(ReverseIteratorModifiers, pop_back)
{
  std::ReverseIterator<int> vi_1(10);
  vi_1.pop_back();
}

TEST(ReverseIteratorModifiers, insert)
{
  std::ReverseIterator<int> vi_1;
  std::ReverseIterator<int> vi_2;
  vi_1.insert(vi_1.begin(), 5);                         // single element(1)
  vi_1.insert(vi_1.begin(), 10, 42);                    // fill(2)
  vi_2.insert(vi_2.begin(), vi_1.begin(), vi_1.end());  // range(3)
}

TEST(ReverseIteratorModifiers, erase)
{
  std::ReverseIterator<int> vi_1(50);
  vi_1.erase(vi_1.begin());
  vi_1.erase(vi_1.begin(), vi_1.end());
}

TEST(ReverseIteratorModifiers, swap)
{
  std::ReverseIterator<int> vi_1(5, 42);
  std::ReverseIterator<int> vi_2(5, 21);
  vi_1.swap(vi_2);
}

TEST(ReverseIteratorModifiers, clear)
{
  std::ReverseIterator<int> vi_1(5, 42);
  vi_1.clear();
}

TEST(ReverseIteratorAllocator, get_allocator)
{
  std::ReverseIterator<int> vi_1(5, 42);
  vi_1.get_allocator();
}

TEST(ReverseIteratorNonMember, swap)
{
  std::ReverseIterator<int> vi_1(5, 42);
  std::ReverseIterator<int> vi_2(5, 21);
  std::swap(vi_1, vi_2);
}

TEST(ReverseIteratorNonMember, relational_operators)
{
  std::ReverseIterator<int> vi_1(5, 42);
  std::ReverseIterator<int> vi_2(5, 42);
  ft::ReverseIterator<int> __vi_1(5, 42);
  ft::ReverseIterator<int> __vi_2(5, 42);
  EXPECT_EQ(vi_1 == vi_2, __vi_1 == __vi_2);
  EXPECT_EQ(vi_1 != vi_2, __vi_1 != __vi_2);
  EXPECT_EQ(vi_1 < vi_2, __vi_1 < __vi_2);
  EXPECT_EQ(vi_1 > vi_2, __vi_1 > __vi_2);
  EXPECT_EQ(vi_1 <= vi_2, __vi_1 <= __vi_2);
  EXPECT_EQ(vi_1 >= vi_2, __vi_1 >= __vi_2);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
