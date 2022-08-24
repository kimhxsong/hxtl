#include "__reverse_iterator.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <typeinfo>

#include "gtest/gtest.h"

TEST(reverse_iterator_typedefs, typedefs) {
  typedef ft::reverse_iterator<std::vector<int>::iterator> __ft__reverse_iterator_t;
  typedef std::reverse_iterator<std::vector<int>::iterator> __std__reverse_iterator_t;

  EXPECT_EQ(typeid(__ft__reverse_iterator_t::iterator_type).name(),
            typeid(__std__reverse_iterator_t::iterator_type).name());
  EXPECT_EQ(typeid(__ft__reverse_iterator_t::iterator_category).name(),
            typeid(__std__reverse_iterator_t::iterator_category).name());
  EXPECT_EQ(typeid(__ft__reverse_iterator_t::value_type).name(),
            typeid(__std__reverse_iterator_t::value_type).name());
  EXPECT_EQ(typeid(__ft__reverse_iterator_t::pointer).name(),
            typeid(__std__reverse_iterator_t::pointer).name());
  EXPECT_EQ(typeid(__ft__reverse_iterator_t::reference).name(),
            typeid(__std__reverse_iterator_t::reference).name());
};

TEST(reverse_iterator_constructor, default__1) {
  ft::reverse_iterator<std::vector<int>::iterator> rev_it;
};

TEST(reverse_iterator_constructor, initialization__2) {
  typedef std::vector<int>::iterator iter_type;

  iter_type __std__vec_it;
  ft::reverse_iterator<iter_type> rev_it(__std__vec_it);
};

TEST(reverse_iterator_constructor, copy__3) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec(42, 42);
  ft::reverse_iterator<iter_type> rev_it(__std__vec.begin());
};

TEST(reverse_iterator_base, base) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_end(__std__vec.begin());
  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end());

  size_t countOfIteration = 0;
  for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it) {
    countOfIteration++;
  }
  EXPECT_EQ(countOfIteration, __std__vec.size());
}

TEST(reverse_iterator_operator, dereference_reference) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end());
  EXPECT_EQ(*rev_begin, *__std__vec.rbegin());
}

TEST(reverse_iterator_operator, addition) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end() - 3);
  EXPECT_EQ(*rev_begin, *(__std__vec.rbegin() + 3));
}

TEST(reverse_iterator_operator, increment) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end());
  EXPECT_EQ(*rev_begin++, *(__std__vec.rbegin()));
  EXPECT_EQ(*rev_begin, *(__std__vec.rbegin() + 1));
  EXPECT_EQ(*++rev_begin, *(__std__vec.rbegin() + 2));
}

TEST(reverse_iterator_operator, advance) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  std::reverse_iterator<iter_type> rev_begin(__std__vec.end());
  rev_begin += 3;
  EXPECT_EQ(*rev_begin, *(__std__vec.rbegin() + 3));
}

TEST(reverse_iterator_operator, substraction) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  std::reverse_iterator<iter_type> rev_end(__std__vec.begin());
  EXPECT_EQ(*(rev_end - 3), *(__std__vec.rend() - 3));
}

TEST(reverse_iterator_operator, decrease) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_end(__std__vec.begin());
  EXPECT_EQ(*rev_end--, *(__std__vec.rend()));
  EXPECT_EQ(*rev_end, *(__std__vec.rend() - 1));
  EXPECT_EQ(*--rev_end, *(__std__vec.rend() - 2));
}

TEST(reverse_iterator_operator, retrocede) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_end(__std__vec.begin());
  rev_end -= 3;
  EXPECT_EQ(*rev_end, *(__std__vec.rend() - 3));
}

TEST(reverse_iterator_operator, dereference_pointer) {
  typedef std::map<int, std::string>::iterator iter_type;

  std::map<int, std::string> numbers;
  numbers[1] = "one";
  numbers[2] = "two";
  numbers[3] = "three";

  ft::reverse_iterator<iter_type> rev_end(numbers.begin());
  ft::reverse_iterator<iter_type> rev_it(numbers.end());

  EXPECT_EQ(rev_it->first == 3 && (rev_it++)->second == "three", true);
  EXPECT_EQ(rev_it->first == 2 && (rev_it++)->second == "two", true);
  EXPECT_EQ(rev_it->first == 1 && (rev_it++)->second == "one", true);
  EXPECT_EQ(rev_it == rev_end, true);
}

TEST(reverse_iterator_operator, dereference_with_offset) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_it(__std__vec.end());
  EXPECT_EQ(rev_it[3], *(__std__vec.rbegin() + 3));
}

TEST(reverse_iterator_non_member, relational_operators) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end());
  ft::reverse_iterator<iter_type> rev_begin2(__std__vec.end());
  ft::reverse_iterator<iter_type> rev_end(__std__vec.begin());

  EXPECT_EQ(rev_begin == rev_begin2, __std__vec.rbegin() == __std__vec.rbegin());
  EXPECT_EQ(rev_begin == rev_end, __std__vec.rbegin() == __std__vec.rend());
  EXPECT_EQ(rev_end == rev_begin, __std__vec.rend() == __std__vec.rbegin());

  EXPECT_EQ(rev_begin != rev_begin2, __std__vec.rbegin() != __std__vec.rbegin());
  EXPECT_EQ(rev_begin != rev_end, __std__vec.rbegin() != __std__vec.rend());
  EXPECT_EQ(rev_end != rev_begin, __std__vec.rend() != __std__vec.rbegin());

  EXPECT_EQ(rev_begin < rev_begin2, __std__vec.rbegin() < __std__vec.rbegin());
  EXPECT_EQ(rev_begin < rev_end, __std__vec.rbegin() < __std__vec.rend());
  EXPECT_EQ(rev_end < rev_begin, __std__vec.rend() < __std__vec.rbegin());

  EXPECT_EQ(rev_begin <= rev_begin2, __std__vec.rbegin() <= __std__vec.rbegin());
  EXPECT_EQ(rev_begin <= rev_end, __std__vec.rbegin() <= __std__vec.rend());
  EXPECT_EQ(rev_end <= rev_begin, __std__vec.rend() <= __std__vec.rbegin());

  EXPECT_EQ(rev_begin > rev_begin2, __std__vec.rbegin() > __std__vec.rbegin());
  EXPECT_EQ(rev_begin > rev_end, __std__vec.rbegin() > __std__vec.rend());
  EXPECT_EQ(rev_end > rev_begin, __std__vec.rend() > __std__vec.rbegin());

  EXPECT_EQ(rev_begin >= rev_begin2, __std__vec.rbegin() >= __std__vec.rbegin());
  EXPECT_EQ(rev_begin >= rev_end, __std__vec.rbegin() >= __std__vec.rend());
  EXPECT_EQ(rev_end >= rev_begin, __std__vec.rend() >= __std__vec.rbegin());

  // EXPECT_EQ(__std__vec.begin() == __std__vec.rend(), true); !NOTE: Does Not Compile
  // EXPECT_EQ(__std__vec.rbegin() == __std__vec.end(), true); !NOTE: Does Not Compile
  // EXPECT_EQ(__std__vec.begin() == rev_end, true); !NOTE: Does Not Compile
  // EXPECT_EQ(rev_begin == __std__vec.end(), true); !NOTE: Does Not Compile
}

TEST(reverse_iterator_non_member_operator, addition) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end());
  ft::reverse_iterator<iter_type> rev_end(__std__vec.begin());

  EXPECT_EQ(*(3 + rev_begin), *(3 + __std__vec.rbegin()));
}

TEST(reverse_iterator_non_member_operator, subtraction) {
  typedef std::vector<int>::iterator iter_type;

  std::vector<int> __std__vec;
  for (int i = 0; i < 10; i++) {
    __std__vec.push_back(i);
  }

  ft::reverse_iterator<iter_type> rev_begin(__std__vec.end());
  ft::reverse_iterator<iter_type> rev_end(__std__vec.begin());

  EXPECT_EQ(rev_end - rev_begin, __std__vec.rend() - __std__vec.rbegin());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
