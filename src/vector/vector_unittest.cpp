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
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(__ft__vec[i], 0);
  }

  ft::vector<int> __ft__vec2(10, 42);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(__ft__vec2[i], 42);
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
  for (int i = 0; i < __ft__vec.size(); i++) {
    EXPECT_EQ(__ft__vec2[i], 42);
  }
}

TEST(vector_iterator, iterator) {
  ft::vector<int> __ft__vec(10);
  __ft__vec.begin();
  __ft__vec.end();
}


// // ITERATORS
// TEST(map_iterator, bidirectional_iterator) {
//   ft::map<std::string,int> __ft__map;
//   __ft__map["a"] = 10;
//   __ft__map["b"] = 20;
//   __ft__map["c"] = 30;
//   __ft__map["d"] = 40;

//   // Is default-constructible, copy-constructible, copy-assignable and destructible
//   ft::map<std::string,int>::iterator __ft__it = __ft__map.begin();
//   ft::map<std::string,int>::iterator __ft__it2(__ft__it);
//   ft::map<std::string,int>::iterator __ft__it3;
//   __ft__it3 = __ft__it2;

//   // Can be compared for equivalence using the equality/inequality operators
//   EXPECT_EQ(__ft__it2 == __ft__it3, true);
//   EXPECT_EQ(__ft__it2 != __ft__map.end(), true);

//   // Can be dereferenced as an rvalue (if in a dereferenceable state).
//   EXPECT_EQ((*__ft__it2).second == 10, true);
//   EXPECT_EQ(__ft__map.begin()->first.size() == std::string("a").size(), true);

//   // For mutable iterators (non-constant iterators):
//   // Can be dereferenced as an lvalue (if in a dereferenceable state).
//   __ft__it2->second = 100;
//   EXPECT_EQ(__ft__it2->second == 100, true);
//   __ft__it2->second = 10;

//   // Can be incremented (if in a dereferenceable state).
//   // The result is either also dereferenceable or a past-the-end iterator.
//   // Two iterators that compare equal, keep comparing equal after being both increased.
//   ++__ft__it;
//   __ft__it++;
//   EXPECT_EQ((*__ft__it++).second == 30, true);
//   EXPECT_EQ((__ft__it)->second == 40, true);

//   --__ft__it;
//   __ft__it--;
//   EXPECT_EQ((*__ft__it--).second == 20, true);
//   EXPECT_EQ((__ft__it)->second == 10, true);
// }

TEST(vector_iterator, reverse_iterator) {
  ft::vector<int> __ft__vec(10);
  __ft__vec.rbegin();
  __ft__vec.rend();
}

TEST(vector_iterator, convertible_to_const_iterator) {
  ft::vector<int>::iterator it;
  ft::vector<int>::const_iterator cit(it);
}

TEST(vector_capacity, capacity) {
  ft::vector<int> __ft__vec(10);
  __ft__vec.size();
  __ft__vec.max_size();
  __ft__vec.resize(20);
  __ft__vec.empty();
  __ft__vec.reserve(40);
}

TEST(vector_elementaceess, element_access) {
  ft::vector<int> __ft__vec(10);
  __ft__vec[0];
  __ft__vec.at(0);
  __ft__vec.front();
  __ft__vec.back();
}

TEST(vector_modifiers, assign) {
  ft::vector<int> __ft__vec(10);
  ft::vector<int> __ft__vec2;
  __ft__vec2.assign(__ft__vec.begin(), __ft__vec.end()); // range(1)
  __ft__vec2.assign(20, 5);  // fill(2)
}

TEST(vector_modifiers, push_back) {
  ft::vector<int> __ft__vec;
  __ft__vec.push_back(10);
}

TEST(vector_modifiers, pop_back) {
  ft::vector<int> __ft__vec(10);
  __ft__vec.pop_back();
}

TEST(vector_modifiers, insert) {
  ft::vector<int> __ft__vec;
  ft::vector<int> __ft__vec2;

  __ft__vec.insert(__ft__vec.begin(), 5);  // single element(1)
  EXPECT_EQ(__ft__vec[0], 5);
  EXPECT_EQ(__ft__vec.size(), 1);

  __ft__vec.insert(__ft__vec.begin(), 10, 42);  // fill(2)
  EXPECT_EQ(__ft__vec[0], 42);
  EXPECT_EQ(__ft__vec[9], 42);
  EXPECT_EQ(__ft__vec[10], 5);
  EXPECT_EQ(__ft__vec.size(), 11);

  __ft__vec2.insert(__ft__vec2.begin(), __ft__vec.begin(), __ft__vec.end());  // range(3)
  EXPECT_EQ(__ft__vec2[0], 42);
  EXPECT_EQ(__ft__vec2[9], 42);
  EXPECT_EQ(__ft__vec2[10], 5);
  EXPECT_EQ(__ft__vec2.size(), 11);
}

TEST(vector_modifiers, erase) {
  ft::vector<int> __ft__vec;
  for (int i = 0; i < 10; i++) {
    __ft__vec.push_back(i);
  }
  __ft__vec.erase(__ft__vec.begin());
  EXPECT_EQ(__ft__vec[0], 1);
  EXPECT_EQ(__ft__vec.size(), 9);

  __ft__vec.erase(__ft__vec.begin()+1, __ft__vec.begin()+3);
  EXPECT_EQ(__ft__vec[1], 4);
  EXPECT_EQ(__ft__vec.size(), 7);

  __ft__vec.erase(__ft__vec.begin(), __ft__vec.end());
  EXPECT_EQ(__ft__vec.size(), 0);
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
