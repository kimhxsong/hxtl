#include "__iterator_traits.hpp"

#include <iterator>
#include <string>
#include <typeinfo>
#include <vector>

#include "gtest/gtest.h"

TEST(iterator_traits, default_template) {
  EXPECT_EQ(typeid(std::iterator_traits<std::vector<int>::iterator>::difference_type).name(),
            typeid(ft::iterator_traits<std::vector<int>::iterator>::difference_type).name());
  EXPECT_EQ(typeid(std::iterator_traits<std::vector<int>::iterator>::value_type).name(),
            typeid(ft::iterator_traits<std::vector<int>::iterator>::value_type).name());
  EXPECT_EQ(typeid(std::iterator_traits<std::vector<int>::iterator>::pointer).name(),
            typeid(ft::iterator_traits<std::vector<int>::iterator>::pointer).name());
  EXPECT_EQ(typeid(std::iterator_traits<std::vector<int>::iterator>::reference).name(),
            typeid(ft::iterator_traits<std::vector<int>::iterator>::reference).name());
  EXPECT_EQ(typeid(std::iterator_traits<std::vector<int>::iterator>::iterator_category).name(),
            typeid(ft::iterator_traits<std::vector<int>::iterator>::iterator_category).name());
};

TEST(iterator_traits, pointer_template) {
  EXPECT_EQ(typeid(std::iterator_traits<int*>::difference_type).name(),
            typeid(ft::iterator_traits<int*>::difference_type).name());
  EXPECT_EQ(typeid(std::iterator_traits<int*>::value_type).name(),
            typeid(ft::iterator_traits<int*>::value_type).name());
  EXPECT_EQ(typeid(std::iterator_traits<int*>::pointer).name(),
            typeid(ft::iterator_traits<int*>::pointer).name());
  EXPECT_EQ(typeid(std::iterator_traits<int*>::reference).name(),
            typeid(ft::iterator_traits<int*>::reference).name());
  EXPECT_EQ(typeid(std::iterator_traits<int*>::iterator_category).name(),
            typeid(ft::iterator_traits<int*>::iterator_category).name());
};

TEST(iterator_traits, const_pointer_template) {
  EXPECT_EQ(typeid(std::iterator_traits<const int*>::difference_type).name(),
            typeid(ft::iterator_traits<const int*>::difference_type).name());
  EXPECT_EQ(typeid(std::iterator_traits<const int*>::value_type).name(),
            typeid(ft::iterator_traits<const int*>::value_type).name());
  EXPECT_EQ(typeid(std::iterator_traits<const int*>::pointer).name(),
            typeid(ft::iterator_traits<const int*>::pointer).name());
  EXPECT_EQ(typeid(std::iterator_traits<const int*>::reference).name(),
            typeid(ft::iterator_traits<const int*>::reference).name());
  EXPECT_EQ(typeid(std::iterator_traits<const int*>::iterator_category).name(),
            typeid(ft::iterator_traits<const int*>::iterator_category).name());
};

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
