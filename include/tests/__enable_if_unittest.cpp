#include "__enable_if.hpp"

#include <typeinfo>

#include "gtest/gtest.h"

TEST(enable_if, true_specialization) {
  EXPECT_EQ(typeid(ft::enable_if<true, int>::type).name(), typeid(int).name());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}