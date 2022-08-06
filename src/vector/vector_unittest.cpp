#include "gtest/gtest.h"

#include <vector>
#include <list>

#if 0
  namespace ft = std;
#else
# include "vector.hpp"
#endif

TEST(vector_constructor, default_constructor) {
  ft::vector<int> __ft__vec;
}

TEST(vector_constructor, fill_constructor) {
  ft::vector<int> __ft__vec(10);
  std::vector<int> __std__vec(__ft__vec.size());
  for (int i = 0; i < __ft__vec.size(); i++) {
    EXPECT_EQ(__ft__vec[i], __std__vec[i]);
  }

  ft::vector<int> __ft__vec2(10, 42);
  std::vector<int> __std__vec2(__ft__vec2.size(), 42);
  for (int i = 0; i < __ft__vec2.size(); i++) {
    EXPECT_EQ(__ft__vec2[i], __std__vec2[i]);
  }
}

TEST(vector_constructor, range_constructor) {
  std::list<int> __std__list;
  for (int i = 0; i < 10; i++) {
    __std__list.push_back(i);
  }
  ft::vector<int> __ft__vec(__std__list.begin(), __std__list.end());
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(__ft__vec[i], i);
  }
}

TEST(vector_constructor, copy_constructor) {
  ft::vector<int> __ft__vec(10, 42);
  ft::vector<int> __ft__vec2(__ft__vec);
  std::vector<int> __std__vec(__ft__vec.size(), 42);

  for (int i = 0; i < __ft__vec.size(); i++) {
    EXPECT_EQ(__ft__vec2[i], __std__vec[i]);
  }
}

TEST(vector_iterator, iterator) {
  ft::vector<int> __ft__vec(10);
  ft::vector<std::string> __ft__vec2(1, "Hello");

  std::vector<int> __std__vec(10);
  std::vector<std::string> __std__vec2(1, "Hello");

  EXPECT_EQ(*__ft__vec2.begin(), *__std__vec2.begin());
  EXPECT_EQ(__ft__vec2.begin()->length(), __std__vec2.begin()->length());

  EXPECT_EQ(*++__ft__vec.begin(), *++__std__vec.begin());
  EXPECT_EQ(*__ft__vec.begin()++, *__std__vec.begin()++);
  EXPECT_EQ(__ft__vec.begin()[0], __std__vec.begin()[0]);
  
  --__ft__vec.end();
  __ft__vec.end()--;

  EXPECT_EQ(__ft__vec.begin() == __ft__vec.begin(), __std__vec.begin() == __std__vec.begin());
  EXPECT_EQ(__ft__vec.begin() == __ft__vec.end(), __std__vec.begin() == __std__vec.end());

  EXPECT_EQ(__ft__vec.begin() != __ft__vec.begin(), __std__vec.begin() != __std__vec.begin());
  EXPECT_EQ(__ft__vec.begin() != __ft__vec.end(), __std__vec.begin() != __std__vec.end());

  EXPECT_EQ(__ft__vec.begin() < __ft__vec.begin(), __std__vec.begin() < __std__vec.begin());
  EXPECT_EQ(__ft__vec.begin() < __ft__vec.end(), __std__vec.begin() < __std__vec.end());

  EXPECT_EQ((__ft__vec.begin()+1) <= __ft__vec.begin(), (__std__vec.begin()+1) <= __std__vec.begin());
  EXPECT_EQ(__ft__vec.begin() <= __ft__vec.end(), __std__vec.begin() <= __std__vec.end());

  EXPECT_EQ(__ft__vec.begin() > __ft__vec.begin(), __std__vec.begin() > __std__vec.begin());
  EXPECT_EQ(__ft__vec.begin() > __ft__vec.end(), __std__vec.begin() > __std__vec.end());

  EXPECT_EQ((__ft__vec.begin()+1) >= __ft__vec.begin(), (__std__vec.begin()+1) >= __std__vec.begin());
  EXPECT_EQ(__ft__vec.begin() >= __ft__vec.end(), __std__vec.begin() >= __std__vec.end());

  EXPECT_EQ(*(__ft__vec.begin() + 3), *(__std__vec.begin() + 3));
  EXPECT_EQ(*(3 + __ft__vec.begin()), *(3 + __ft__vec.begin()));

  EXPECT_EQ(__ft__vec.end() - __ft__vec.begin(), __std__vec.end() - __std__vec.begin());

  ft::vector<int>::iterator __ft__it = __ft__vec.begin();
  std::vector<int>::iterator __std__it = __std__vec.begin();
  __ft__it += 3;
  __std__it += 3;
  EXPECT_EQ(*__ft__it, *__std__it);
  __ft__it -= 2;
  __std__it -= 2;
  EXPECT_EQ(*__ft__it, *__std__it);
}

TEST(vector_iterator, reverse_iterator) {
ft::vector<int> __ft__vec(10);
  ft::vector<std::string> __ft__vec2(1, "Hello");

  std::vector<int> __std__vec(10);
  std::vector<std::string> __std__vec2(1, "Hello");

  EXPECT_EQ(*__ft__vec2.rbegin(), *__std__vec2.rbegin());
  EXPECT_EQ(__ft__vec2.rbegin()->length(), __std__vec2.rbegin()->length());

  EXPECT_EQ(*++__ft__vec.rbegin(), *++__std__vec.rbegin());
  EXPECT_EQ(*__ft__vec.rbegin()++, *__std__vec.rbegin()++);
  EXPECT_EQ(__ft__vec.rbegin()[0], __std__vec.rbegin()[0]);
  
  --__ft__vec.rend();
  __ft__vec.rend()--;

  EXPECT_EQ(__ft__vec.rbegin() == __ft__vec.rbegin(), __std__vec.rbegin() == __std__vec.rbegin());
  EXPECT_EQ(__ft__vec.rbegin() == __ft__vec.rend(), __std__vec.rbegin() == __std__vec.rend());

  EXPECT_EQ(__ft__vec.rbegin() != __ft__vec.rbegin(), __std__vec.rbegin() != __std__vec.rbegin());
  EXPECT_EQ(__ft__vec.rbegin() != __ft__vec.rend(), __std__vec.rbegin() != __std__vec.rend());

  EXPECT_EQ(__ft__vec.rbegin() < __ft__vec.rbegin(), __std__vec.rbegin() < __std__vec.rbegin());
  EXPECT_EQ(__ft__vec.rbegin() < __ft__vec.rend(), __std__vec.rbegin() < __std__vec.rend());

  EXPECT_EQ((__ft__vec.rbegin()+1) <= __ft__vec.rbegin(), (__std__vec.rbegin()+1) <= __std__vec.rbegin());
  EXPECT_EQ(__ft__vec.rbegin() <= __ft__vec.rend(), __std__vec.rbegin() <= __std__vec.rend());

  EXPECT_EQ(__ft__vec.rbegin() > __ft__vec.rbegin(), __std__vec.rbegin() > __std__vec.rbegin());
  EXPECT_EQ(__ft__vec.rbegin() > __ft__vec.rend(), __std__vec.rbegin() > __std__vec.rend());

  EXPECT_EQ((__ft__vec.rbegin()+1) >= __ft__vec.rbegin(), (__std__vec.rbegin()+1) >= __std__vec.rbegin());
  EXPECT_EQ(__ft__vec.rbegin() >= __ft__vec.rend(), __std__vec.rbegin() >= __std__vec.rend());

  EXPECT_EQ(*(__ft__vec.rbegin() + 3), *(__std__vec.rbegin() + 3));
  EXPECT_EQ(*(3 + __ft__vec.rbegin()), *(3 + __ft__vec.rbegin()));

  EXPECT_EQ(__ft__vec.rend() - __ft__vec.rbegin(), __std__vec.rend() - __std__vec.rbegin());

  ft::vector<int>::reverse_iterator __ft__it = __ft__vec.rbegin();
  std::vector<int>::reverse_iterator __std__it = __std__vec.rbegin();
  __ft__it += 3;
  __std__it += 3;
  EXPECT_EQ(*__ft__it, *__std__it);
  __ft__it -= 2;
  __std__it -= 2;
  EXPECT_EQ(*__ft__it, *__std__it);
}

TEST(vector_iterator, convertible_to_const) {
  ft::vector<int> __ft__vec;
  ft::vector<int>::iterator __ft__it(__ft__vec.begin());
  ft::vector<int>::const_iterator __ft__cit(__ft__it);
  ft::vector<int>::const_iterator __ft__cit2(__ft__cit);
  // ft::vector<int>::iterator __ft__it2(__ft__cit2);  // !NOTE: Does Not Compile

  ft::vector<int>::reverse_iterator __ft__rit(__ft__it);
  ft::vector<int>::const_reverse_iterator __std__crit(__ft__rit);
  ft::vector<int>::const_reverse_iterator __std__crit2(__std__crit);
  ft::vector<int>::const_reverse_iterator __std__crit3(__ft__it);
  ft::vector<int>::const_reverse_iterator __std__crit4(__ft__cit);
  // ft::vector<int>::reverse_iterator __ft__rit2(__std__crit); !NOTE: Does Not Compile
}

TEST(vector_capacity, capacity) {
  ft::vector<int> __ft__vec(10);
  std::vector<int> __std__vec(10);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());
  EXPECT_EQ(__ft__vec.max_size(), __std__vec.max_size());
  __ft__vec.resize(20);
  __std__vec.resize(20);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());
  EXPECT_EQ(__ft__vec.empty(), false);
  EXPECT_EQ(__ft__vec.empty(), __std__vec.empty());

  __ft__vec.reserve(40);
  __std__vec.reserve(40);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());  // TODO
  //   vector_unittest.cpp:72: Failure
  // Expected equality of these values:
  //   __ft__vec.size()
  //     Which is: 20
  //   40

  __ft__vec.reserve(30);
  __std__vec.reserve(30);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());
  EXPECT_EQ(__ft__vec.capacity(), __std__vec.capacity());
  //   vector_unittest.cpp:74: Failure
  // Expected equality of these values:
  //   __ft__vec.size()
  //     Which is: 20
  //   40
  __ft__vec.resize(30);
  EXPECT_EQ(__ft__vec.size(), 30);
}

TEST(vector_elementaceess, element_access) {
  ft::vector<int> __ft__vec(10);
  std::vector<int> __std__vec(10);
  for (int i = 0; i < 10; i++) {
    __ft__vec.push_back(i);
    __std__vec.push_back(i);
  }

  EXPECT_EQ(__ft__vec[0], __std__vec[0]);
  EXPECT_EQ(__ft__vec.at(1), __std__vec.at(1));  // TODO
  // vector_unittest.cpp:112: Failure
  // Expected equality of these values:
  //   __ft__vec.at(1)
  //     Which is: -1879048192
  //   __std__vec.at(1)
  //     Which is: 0

  // __ft__vec.at(__ft__vec.capacity());
  // unknown file: Failure
  // C++ exception with description "at" thrown in the test body.

  try {
    __ft__vec.at(__ft__vec.capacity());
  } catch (const std::out_of_range& oor) {
  }

  EXPECT_EQ(__ft__vec.front(), __std__vec.front());
  EXPECT_EQ(__ft__vec.back(), __std__vec.back());
}

TEST(vector_modifiers, assign) {
  std::vector<int> __std__vec(10, 42);
  std::vector<int> __std__vec2(20, 5);
  ft::vector<int> __ft__vec(10, 42);
  ft::vector<int> __ft__vec2;

  __ft__vec2.assign(__ft__vec.begin(), __ft__vec.end()); // range(1)
  for (int i = 0; i < __std__vec.size(); i++) {
    EXPECT_EQ(__std__vec[i], __ft__vec2[i]);
  }

  __ft__vec2.assign(20, 5);  // fill(2)
  for (int i = 0; i < __std__vec2.size(); i++) {
    EXPECT_EQ(__std__vec2[i], __ft__vec2[i]);
  }
}

TEST(vector_modifiers, push_back) {
  ft::vector<int> __ft__vec;
  std::vector<int> __std__vec;

  srand(0);
  for (int i = 0; i < 5; i++)  {
    int random_value = rand() % 10;
    __ft__vec.push_back(random_value);
    __std__vec.push_back(random_value);
  }

  for (int i = 0; i < 5; i++)  {
    EXPECT_EQ(__ft__vec[i], __std__vec[i]);
  }
}

TEST(vector_modifiers, pop_back) {
  ft::vector<int> __ft__vec(10);
  __ft__vec.pop_back();
  EXPECT_EQ(__ft__vec.size(), 9);
  for (size_t size = __ft__vec.size(); size > 0; size--) {
    __ft__vec.pop_back();
  }
  EXPECT_EQ(__ft__vec.size(), 0);

  // std::vector<int> __std__vec;
  // ft::vector<int> __ft__vec2;
  // __ft__vec2.pop_back();
  // __std__vec.pop_back();
  // EXPECT_EQ(__ft__vec2.size(), __std__vec.size());
  // Expected equality of these values:
  // __ft__vec2.size()
  //   Which is: 4294967295
  // __std__vec.size()
  //   Which is: 18446744073709551615
}

TEST(vector_modifiers, insert) {
  ft::vector<int> __ft__vec;
  ft::vector<int> __ft__vec2;

  std::vector<int> __std__vec;
  std::vector<int> __std__vec2;

  __ft__vec.insert(__ft__vec.begin(), 5);  // single element(1)
  __std__vec.insert(__std__vec.begin(), 5);  // single element(1)
  EXPECT_EQ(__ft__vec[0], __std__vec[0]);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());

  __ft__vec.insert(__ft__vec.begin(), 10, 42);  // fill(2)
  __std__vec.insert(__std__vec.begin(), 10, 42);  // fill(2)
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());
  EXPECT_EQ(__ft__vec[0], __std__vec[0]);
  EXPECT_EQ(__ft__vec[9], __std__vec[9]);
  EXPECT_EQ(__ft__vec[10], __std__vec[10]);

  __ft__vec2.insert(__ft__vec2.begin(), __ft__vec.begin(), __ft__vec.end());  // range(3)
  __std__vec2.insert(__std__vec2.begin(), __std__vec.begin(), __std__vec.end());
  EXPECT_EQ(__ft__vec2[0], __std__vec2[0]);
  EXPECT_EQ(__ft__vec2[9], __std__vec2[9]);
  EXPECT_EQ(__ft__vec2[10], __std__vec2[10]);
  EXPECT_EQ(__ft__vec2.size(), __std__vec2.size());
}

TEST(vector_modifiers, erase) {
  ft::vector<int> __ft__vec;
  std::vector<int> __std__vec;

  for (int i = 0; i < 10; i++) {
    __ft__vec.push_back(i);
    __std__vec.push_back(i);
  }

  __ft__vec.erase(__ft__vec.begin());
  __std__vec.erase(__std__vec.begin());
  EXPECT_EQ(__ft__vec[0], __std__vec[0]);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());

  ft::vector<int>::iterator __ft__it = __ft__vec.erase(__ft__vec.begin()+1, __ft__vec.begin()+3);
  std::vector<int>::iterator __std__it = __std__vec.erase(__std__vec.begin()+1, __std__vec.begin()+3);

  EXPECT_EQ(*__ft__it, *__std__it);
  EXPECT_EQ(__ft__vec[1], __std__vec[1]);
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());

  __ft__vec.erase(__ft__vec.begin(), __ft__vec.end());
  __std__vec.erase(__std__vec.begin(), __std__vec.end());
  EXPECT_EQ(__ft__vec.size(), __std__vec.size());
}

TEST(vector_modifiers, swap) {
  ft::vector<int> __ft__vec(5, 42);
  ft::vector<int> __ft__vec2(5, 21);
  ft::vector<int> __ft__vec3(__ft__vec2);
  __ft__vec.swap(__ft__vec2);
  for (int i = 0; i < __ft__vec.size(); i++) {
    EXPECT_EQ(__ft__vec[i], __ft__vec3[i]);
  }
}

TEST(vector_modifiers, clear) {
  ft::vector<int> __ft__vec(5, 42);
  __ft__vec.clear();
  EXPECT_EQ(__ft__vec.size(), 0);
  // A reallocation is not guaranteed to happen, and the vector capacity is not
  // guaranteed to change due to calling this function. 
  // EXPECT_EQ(__ft__vec.capacity(), 0);  !NOTE: Not guaranteed
  ft::vector<int>().swap(__ft__vec);
  EXPECT_EQ(__ft__vec.capacity(), 0);
}

TEST(vector_allocator, get_allocator) {
  ft::vector<int>::allocator_type alloc;
  ft::vector<int> __ft__vec(alloc);
  EXPECT_EQ(alloc, __ft__vec.get_allocator());
}

TEST(vector_nonmember, swap) {
  ft::vector<int> __ft__vec(5, 42);
  ft::vector<int> __ft__vec2(5, 21);
  ft::vector<int> __ft__vec3(__ft__vec2);
  swap(__ft__vec, __ft__vec2);
  for (int i = 0; i < __ft__vec.size(); i++) {
    EXPECT_EQ(__ft__vec[i], __ft__vec3[i]);
  }
}

TEST(vector_nonmember, relational_operators) {
  ft::vector<int> __ft__vec(5, 42);
  ft::vector<int> __ft__vec2(5, 21);
  ft::vector<int> __ft__vec3(10, 42);

  std::vector<int> __std__vec(5, 42);
  std::vector<int> __std__vec2(5, 21);
  std::vector<int> __std__vec3(10, 42);

  EXPECT_EQ(__ft__vec == __ft__vec2, __std__vec == __std__vec2);
  EXPECT_EQ(__ft__vec == __ft__vec3, __std__vec == __std__vec3);
  EXPECT_EQ(__ft__vec2 == __ft__vec3, __std__vec2 == __std__vec3);

  EXPECT_EQ(__ft__vec != __ft__vec2, __std__vec != __std__vec2);
  EXPECT_EQ(__ft__vec != __ft__vec3, __std__vec != __std__vec3);
  EXPECT_EQ(__ft__vec2 != __ft__vec3, __std__vec2 != __std__vec3);

  EXPECT_EQ(__ft__vec < __ft__vec2, __std__vec < __std__vec2);
  EXPECT_EQ(__ft__vec < __ft__vec3, __std__vec < __std__vec3);
  EXPECT_EQ(__ft__vec2 < __ft__vec3, __std__vec2 < __std__vec3);

  EXPECT_EQ(__ft__vec <= __ft__vec2, __std__vec <= __std__vec2);
  EXPECT_EQ(__ft__vec <= __ft__vec3, __std__vec <= __std__vec3);
  EXPECT_EQ(__ft__vec2 <= __ft__vec3, __std__vec2 <= __std__vec3);

  EXPECT_EQ(__ft__vec > __ft__vec2, __std__vec > __std__vec2);
  EXPECT_EQ(__ft__vec > __ft__vec3, __std__vec > __std__vec3);
  EXPECT_EQ(__ft__vec2 > __ft__vec3, __std__vec2 > __std__vec3);

  EXPECT_EQ(__ft__vec >= __ft__vec2, __std__vec >= __std__vec2);
  EXPECT_EQ(__ft__vec >= __ft__vec3, __std__vec >= __std__vec3);
  EXPECT_EQ(__ft__vec2 >= __ft__vec3, __std__vec2 >= __std__vec3);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
