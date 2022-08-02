
#include <iostream>
#include <iterator>
#include <string>
#include <iterator>

#include "gtest/gtest.h"

namespace ft = std;

TEST(reverse_iteratorConstructor, default_constructor) {
  std::reverse_iterator<int> vi_1;
  ft::reverse_iterator<int> vi_2;

  EXPECT_EQ(vi_1.size(), vi_2.size());
  std::reverse_iterator<std::string> vstr_1;
  ft::reverse_iterator<std::string> vstr_2;
}

TEST(reverse_iteratorConstructor, fill_constructor) {
  std::reverse_iterator<int> vi_1(10);
  std::reverse_iterator<std::string> vstr_1(10);
}

TEST(reverse_iteratorConstructor, range_constructor) {
  std::reverse_iterator<int> vi_1;
  std::reverse_iterator<int> vi_2(vi_1.begin(), vi_1.end());
}

TEST(reverse_iteratorConstructor, copy_constructor) {
  std::reverse_iterator<int> vi_1;
  std::reverse_iterator<int> vi_2(vi_1);
}

TEST(reverse_iteratorIterator, iterator) {
  std::reverse_iterator<int> vi_1(10);
  vi_1.begin();
  vi_1.end();
}

TEST(reverse_iteratorIterator, reverse_iterator) {
  std::reverse_iterator<int> vi_1(10);
  vi_1.rbegin();
  vi_1.rend();
}

TEST(reverse_iteratorIterator, convertible_to_const_iterator) {
  std::reverse_iterator<int>::iterator it;
  std::reverse_iterator<int>::const_iterator cit(it);
}

TEST(reverse_iteratorCapacity, capacity) {
  std::reverse_iterator<int> vi_1(10);
  vi_1.size();
  vi_1.max_size();
  vi_1.resize(20);
  vi_1.empty();
  vi_1.reserve(40);
}

TEST(reverse_iteratorElementAceess, element_access) {
  std::reverse_iterator<int> vi_1(10);
  vi_1[0];
  vi_1.at(0);
  vi_1.front();
  vi_1.back();
}

TEST(reverse_iteratorModifiers, assign) {
  std::reverse_iterator<int> vi_1(10);
  std::reverse_iterator<int> vi_2;
  vi_2.assign(vi_1.begin(), vi_1.end()); // range(1)
  vi_2.assign(20, 5);  // fill(2)
}

TEST(reverse_iteratorModifiers, push_back) {
  std::reverse_iterator<int> vi_1;
  vi_1.push_back(10);
}

TEST(reverse_iteratorModifiers, pop_back) {
  std::reverse_iterator<int> vi_1(10);
  vi_1.pop_back();
}

TEST(reverse_iteratorModifiers, insert) {
  std::reverse_iterator<int> vi_1;
  std::reverse_iterator<int> vi_2;
  vi_1.insert(vi_1.begin(), 5);  // single element(1)
  vi_1.insert(vi_1.begin(), 10, 42);  // fill(2)
  vi_2.insert(vi_2.begin(), vi_1.begin(), vi_1.end());  // range(3)
}

TEST(reverse_iteratorModifiers, erase) {
  std::reverse_iterator<int> vi_1(50);
  vi_1.erase(vi_1.begin());
  vi_1.erase(vi_1.begin(), vi_1.end());
}

TEST(reverse_iteratorModifiers, swap) {
  std::reverse_iterator<int> vi_1(5, 42);
  std::reverse_iterator<int> vi_2(5, 21);
  vi_1.swap(vi_2);
}

TEST(reverse_iteratorModifiers, clear) {
  std::reverse_iterator<int> vi_1(5, 42);
  vi_1.clear();
}

TEST(reverse_iteratorAllocator, get_allocator) {
  std::reverse_iterator<int> vi_1(5, 42);
  vi_1.get_allocator();
}

TEST(reverse_iteratorNonMember, swap) {
  std::reverse_iterator<int> vi_1(5, 42);
  std::reverse_iterator<int> vi_2(5, 21);
  std::swap(vi_1, vi_2);
}

TEST(reverse_iteratorNonMember, relational_operators) {
  std::reverse_iterator<int> vi_1(5, 42);
  std::reverse_iterator<int> vi_2(5, 42);
  ft::reverse_iterator<int> __vi_1(5, 42);
  ft::reverse_iterator<int> __vi_2(5, 42);
  EXPECT_EQ(vi_1 == vi_2, __vi_1 == __vi_2);
  EXPECT_EQ(vi_1 != vi_2, __vi_1 != __vi_2);
  EXPECT_EQ(vi_1 < vi_2, __vi_1 < __vi_2);
  EXPECT_EQ(vi_1 > vi_2, __vi_1 > __vi_2);
  EXPECT_EQ(vi_1 <= vi_2, __vi_1 <= __vi_2);
  EXPECT_EQ(vi_1 >= vi_2, __vi_1 >= __vi_2);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
