#include "__is_integral.hpp"

#include "gtest/gtest.h"

TEST(is_integral, non_cv)
{
  // EXPECT_EQ(ft::is_integral<int>::value, true);  // !NOTE: Does Not Compile
  EXPECT_EQ(ft::is_integral<unsigned char>::value == true, true);
  EXPECT_EQ(ft::is_integral<unsigned short>::value == true, true);
  EXPECT_EQ(ft::is_integral<unsigned int>::value == true, true);
  EXPECT_EQ(ft::is_integral<unsigned long>::value == true, true);

  EXPECT_EQ(ft::is_integral<signed char>::value == true, true);
  EXPECT_EQ(ft::is_integral<short>::value == true, true);
  EXPECT_EQ(ft::is_integral<int>::value == true, true);
  EXPECT_EQ(ft::is_integral<long>::value == true, true);

  EXPECT_EQ(ft::is_integral<char>::value == true, true);
  EXPECT_EQ(ft::is_integral<bool>::value == true, true);

  EXPECT_EQ(ft::is_integral<float>::value == false, true);
  EXPECT_EQ(ft::is_integral<double>::value == false, true);
}

TEST(is_integral, cv_qualified)
{
  EXPECT_EQ(ft::is_integral<int>::value == true, true);
  EXPECT_EQ(ft::is_integral<const int>::value == true, true);
  EXPECT_EQ(ft::is_integral<volatile int>::value == true, true);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
