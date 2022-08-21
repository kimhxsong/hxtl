#include <gtest/gtest.h>

#include "__tree.hpp"

TEST(tree_constructor, default_constructor) {
  ft::__tree<int> mytree;
  ft::__tree<int> mytree2;
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}