#include <iostream>
#include <string>
#include <utility>

#include "gtest/gtest.h"

#if 1
namespace ft = std;
#else
# include "../pair.hpp"
#endif

TEST(pair_constructor, default__1) {
  ft::pair<std::string, int> __ft__pr;
}

TEST(pair_constructor, copy__2) {
  ft::pair<std::string, int> __ft__pr;
  ft::pair<std::string, int> __ft__pr2(__ft__pr);

  EXPECT_EQ(__ft__pr.first, __ft__pr2.first);
  EXPECT_EQ(__ft__pr.second, __ft__pr2.second);
}

TEST(pair_constructor, initialization__3) {
  ft::pair<std::string, int> __ft__pr("Answer", 42);
  ft::pair<std::string, int> __ft__pr2(__ft__pr);

  EXPECT_EQ(__ft__pr.first, __ft__pr2.first);
  EXPECT_EQ(__ft__pr.second, __ft__pr2.second);
}

TEST(pair_operator, assign_operator) {
  ft::pair<std::string, int> __ft__pr("Answer", 42);
  ft::pair<std::string, int> __ft__pr2;

  __ft__pr2 = __ft__pr;

  EXPECT_EQ(__ft__pr.first, __ft__pr2.first);
  EXPECT_EQ(__ft__pr.second, __ft__pr2.second);
}

// Relational operators for pair
// Performs the appropriate comparison operation between the pair objects lhs and rhs.

// Two pair objects compare equal to each other if both their first members compare
// equal to each other and both their second members compare also equal to each other
// in both cases using operator== for the comparison).

// Similarly, operators <, >, <= and >= perform a lexicographical comparison
// on the sequence formed by members first and second (in all cases using operator<
// reflexively for the comparisons).

TEST(pair_operator, relational_operators) {
  ft::pair<std::string, int> __ft__pr("Answer", 42);
  ft::pair<std::string, int> __ft__pr2(__ft__pr);
  EXPECT_EQ(__ft__pr == __ft__pr2, true);
  __ft__pr2.second = 21;
  EXPECT_EQ(__ft__pr != __ft__pr2, true); // because __ft__pr.first == __ft__pr2.first is true.
  __ft__pr.first = "answer";
  EXPECT_EQ(__ft__pr > __ft__pr2, true);
  EXPECT_EQ(__ft__pr >= __ft__pr2, true);
  EXPECT_EQ(__ft__pr < __ft__pr2, false);
  EXPECT_EQ(__ft__pr <= __ft__pr2, false);

  const ft::pair<std::string, int> __ft__cpr("Answer", 21);
  EXPECT_EQ(__ft__pr != __ft__cpr, true);
  EXPECT_EQ(__ft__pr == __ft__cpr, false);
  EXPECT_EQ(__ft__pr > __ft__cpr, true);
  EXPECT_EQ(__ft__pr >= __ft__cpr, true);
  EXPECT_EQ(__ft__pr < __ft__cpr, false);
  EXPECT_EQ(__ft__pr <= __ft__cpr, false);

  EXPECT_EQ(__ft__cpr != __ft__cpr, false);
  EXPECT_EQ(__ft__cpr > __ft__cpr, false);
  EXPECT_EQ(__ft__cpr >= __ft__cpr, true);
  EXPECT_EQ(__ft__cpr < __ft__cpr, false);
  EXPECT_EQ(__ft__cpr <= __ft__cpr, true);
}

TEST(pair_non_member_function, make_pair) {
  ft::pair<std::string, int> __ft__pr;
  EXPECT_EQ(__ft__pr, ft::make_pair(std::string(), int()));

  ft::pair<std::string, int> __ft__pr2("Answer", 42);
  EXPECT_EQ(__ft__pr2, ft::make_pair(std::string("Answer"), 42));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
