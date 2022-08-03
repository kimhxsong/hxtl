#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "gtest/gtest.h"

namespace ft = std;
// #include "../map.hpp"

// MAP_CONSTRUCTOR
// explicit map (const key_compare& comp = key_compare(),
//              const allocator_type& alloc = allocator_type());
TEST(map_constructor, empty__1__) {
  std::map<char, int> __std__map;
  ft::map<char, int> __ft__map;
  EXPECT_EQ(__std__map.size(), __ft__map.size());
}

// template <class InputIterator>
// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
//     const allocator_type& alloc = allocator_type());
TEST(map_constructor, range__2__) {
  std::vector<std::pair<char,int> > __std__vec_with_pair;
  for (int i = 33; i < 127; i++) {
    __std__vec_with_pair.push_back(std::make_pair(static_cast<char>(i), i));
  }

  std::map<char, int> __std__map(__std__vec_with_pair.begin(), __std__vec_with_pair.end());
  ft::map<char, int> __ft__map(__std__vec_with_pair.begin(), __std__vec_with_pair.end());

  EXPECT_EQ(__std__map.size(), __ft__map.size());
}

// map(const map& x);
TEST(map_constructor, copy__3__) {
  std::map<char,int> __std__map;
  std::map<char,int> __ft__map(__std__map);

  EXPECT_EQ(__std__map.size(), __ft__map.size());
}

TEST(map_operator, assign) {
  std::vector<std::pair<char,int> > __std__vec_with_pair;
  for (int i = 33; i < 127; i++) {
    __std__vec_with_pair.push_back(std::make_pair(static_cast<char>(i), i));
  }

  std::map<char, int> __std__map(__std__vec_with_pair.begin(), __std__vec_with_pair.end());
  std::map<char, int> __std__map2(__std__map);

  ft::map<char, int> __ft__map(__std__vec_with_pair.begin(), __std__vec_with_pair.end());
  ft::map<char, int> __ft__map2(__ft__map);

  EXPECT_EQ(__std__map2.size(), __ft__map2.size());
}

// GETTER
TEST(map_getter, get_allocator) {
    std::map<char,int> __std__map;
    std::map<char,int>::allocator_type __std__alloc =  __std__map.get_allocator();

    ft::map<char,int> __ft__map;
    ft::map<char,int>::allocator_type __ft__alloc = __ft__map.get_allocator();
}


// ITERATORS
TEST(map_iterator, iterator) {
  std::map<std::string,int> __std__map;
  __std__map["a"] = 10;
  __std__map["b"] = 20;
  __std__map["c"] = 30;
  __std__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  std::map<std::string,int>::iterator __std__it = __std__map.begin();
  std::map<std::string,int>::iterator __std__it2(__std__it);
  std::map<std::string,int>::iterator __std__it3;
  __std__it3 = __std__it2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__std__it2 == __std__it3, true);
  EXPECT_EQ(__std__it2 != __std__map.end(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__std__it2).second == 10, true);
  EXPECT_EQ(__std__map.begin()->first.size() == std::string("a").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
  __std__it2->second = 100;
  EXPECT_EQ(__std__it2->second == 100, true);
  __std__it2->second = 10;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__std__it;
  __std__it++;
  EXPECT_EQ((*__std__it++).second == 30, true);
  EXPECT_EQ((__std__it)->second == 40, true);

  --__std__it;
  __std__it--;
  EXPECT_EQ((*__std__it--).second == 20, true);
  EXPECT_EQ((__std__it)->second == 10, true);
}

// ITERATORS
TEST(map_iterator, const_iterator) {
  std::map<std::string,int> __std__map;
  __std__map["a"] = 10;
  __std__map["b"] = 20;
  __std__map["c"] = 30;
  __std__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  std::map<std::string,int>::const_iterator __std__cit = __std__map.begin();
  std::map<std::string,int>::const_iterator __std__cit2(__std__cit);
  std::map<std::string,int>::const_iterator __std__cit3;
  __std__cit3 = __std__cit2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__std__cit2 == __std__cit3, true);
  EXPECT_EQ(__std__cit2 != __std__map.end(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__std__cit2).second == 10, true);
  EXPECT_EQ(__std__map.begin()->first.size() == std::string("a").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
//   __std__cit2->second = 100; // !NOTE: Does Not Compile.
//   EXPECT_EQ(__std__cit2->second == 100, true);
//   __std__cit2->second = 10;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__std__cit;
  __std__cit++;
  EXPECT_EQ((*__std__cit++).second == 30, true);
  EXPECT_EQ((__std__cit)->second == 40, true);

  --__std__cit;
  __std__cit--;
  EXPECT_EQ((*__std__cit--).second == 20, true);
  EXPECT_EQ((__std__cit)->second == 10, true);
}

TEST(map_iterator, reverse_iterator) {
  std::map<std::string,int> __std__map;
  __std__map["a"] = 10;
  __std__map["b"] = 20;
  __std__map["c"] = 30;
  __std__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  std::map<std::string,int>::reverse_iterator __std__rit = __std__map.rbegin();
  std::map<std::string,int>::reverse_iterator __std__rit2(__std__rit);
  std::map<std::string,int>::reverse_iterator __std__rit3;
  __std__rit3 = __std__rit2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__std__rit2 == __std__rit3, true);
  EXPECT_EQ(__std__rit2 != __std__map.rend(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__std__rit2).second == 40, true);
  EXPECT_EQ(__std__map.rbegin()->first.size() == std::string("d").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
  __std__rit2->second = 400;
  EXPECT_EQ(__std__rit2->second == 400, true);
  __std__rit2->second = 40;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__std__rit;
  __std__rit++;
  EXPECT_EQ((*__std__rit++).second == 20, true);
  EXPECT_EQ((__std__rit)->second == 10, true);

  --__std__rit;
  __std__rit--;
  EXPECT_EQ((*__std__rit--).second == 30, true);
  EXPECT_EQ((__std__rit)->second == 40, true);
}

// ITERATORS
TEST(map_iterator, const_reverse_iterator) {
  std::map<std::string,int> __std__map;
  __std__map["a"] = 10;
  __std__map["b"] = 20;
  __std__map["c"] = 30;
  __std__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  std::map<std::string,int>::const_reverse_iterator __std__crit = __std__map.rbegin();
  std::map<std::string,int>::const_reverse_iterator __std__crit2(__std__crit);
  std::map<std::string,int>::const_reverse_iterator __std__crit3;
  __std__crit3 = __std__crit2;
  std::map<std::string,int>::const_reverse_iterator __std__crit4(__std__map.begin());  // copy iterator to reverse_iterator

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__std__crit2 == __std__crit3, true);
  EXPECT_EQ(__std__crit2 != __std__map.rend(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__std__crit2).second == 40, true);
  EXPECT_EQ(__std__map.rbegin()->first.size() == std::string("a").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
//   __std__crit2->second = 400; // !NOTE: Does Not Compile.
//   EXPECT_EQ(__std__crit2->second == 400, true);
//   __std__crit2->second = 40;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__std__crit;
  __std__crit++;
  EXPECT_EQ((*__std__crit++).second == 20, true);
  EXPECT_EQ((__std__crit)->second == 10, true);

  --__std__crit;
  __std__crit--;
  EXPECT_EQ((*__std__crit--).second == 30, true);
  EXPECT_EQ((__std__crit)->second == 40, true);
}

TEST(map_iterator, convertible) {
  std::map<char,int> __std__map;
  std::map<char,int>::iterator __std__it(__std__map.begin());
  std::map<char,int>::const_iterator __std__cit(__std__it);
  std::map<char,int>::const_iterator __std__cit2(__std__cit);
  // std::map<char,int>::iterator __std__it2(__std__cit2);  // !NOTE: Does Not Compile

  std::map<char,int>::reverse_iterator __std__rit(__std__it);
  std::map<char,int>::const_reverse_iterator __std__crit(__std__rit);
  std::map<char,int>::const_reverse_iterator __std__crit2(__std__crit);
  std::map<char,int>::const_reverse_iterator __std__crit3(__std__it);
  std::map<char,int>::const_reverse_iterator __std__crit4(__std__cit);
  // std::map<char,int>::reverse_iterator __std__rit2(__std__crit); !NOTE: Does Not Compile

  ft::map<char,int> __ft__map;
  ft::map<char,int>::iterator __ft__it(__ft__map.begin());
  ft::map<char,int>::const_iterator __ft__cit(__ft__it);
  ft::map<char,int>::const_iterator __ft__cit2(__ft__cit);
}

// TEST(mapCapacity, capacity) {
//   std::map<char,int> __std__map;
//   __std__map.empty();
//   __std__map.size();
//   __std__map.max_size();
// }

// TEST(mapElementAceess, element_access) {
//   std::map<char,int> __std__map;
//   __std__map["answer"] = 42;
//   EXPECT_EQ(__std__map["answer"], 42);
// }

// TEST(mapModifiers, insert) {
//   std::map<char,int> __std__map;
//   std::map<char,int> __ft__map;

//   __std__map.insert(std::pair<char,int>("zero", 0));  // single element(1)
//   __std__map.insert(std::pair<char,int>("answer", 42)); 

//   std::pair<std::map<char,int>::iterator, bool> ret;
//   ret = __std__map.insert(std::pair<char,int>("answer", 42));  // with hint(2)
//   EXPECT_EQ(ret.second, false);

//   __ft__map.insert(__std__map.begin(), __std__map.end());  // range(3)
// }

// TEST(mapModifiers, erase) {
//   std::map<char,int> mci_1;
//   std::map<char,int>::iterator it;
//   mci_1['a']=10;
//   mci_1['b']=20;
//   mci_1['c']=30;
//   mci_1['d']=40;
//   it= mci_1.begin();
//   mci_1.erase(it);                   // erasing by iterator
//   mci_1.erase('c');                  // erasing by key
//   it=mci_1.find ('d');
//   mci_1.erase(it, mci_1.end());    // erasing by range
// }

// TEST(mapModifiers, swap) {
//   std::map<char, int> mci_1;
//   std::map<char, int> mci_2;
//   mci_1['x'] = 100;
//   mci_1['y'] = 200;
//   mci_2['a'] = 100;
//   mci_2['b'] = 200;
//   mci_2['c'] = 300;
//   std::map<char, int> mci_1__copied(mci_1);
//   mci_1.swap(mci_2);
//   EXPECT_EQ(mci_1, mci_1__copied);
// }

// TEST(mapModifiers, clear) {
//   std::map<char, int> mci_1;
//   std::map<char, int> mci_2;
//   mci_1['x'] = 100;
//   mci_1['y'] = 200;
//   mci_1.clear();
//   mci_1['x'] = 1100;
//   mci_1['y'] = 2200;
//   EXPECT_EQ(mci_1['x'], 1100);
//   EXPECT_EQ(mci_1['y'], 2200);
// }

// TEST(mapObserver, key_comp) {
//   std::map<char,int> mci_1;
//   std::map<char,int>::key_compare mci_cmp = mci_1.key_comp();
//   ft::map<char,int> __mci_1;
//   ft::map<char,int>::key_compare __mci_cmp = __mci_1.key_comp();
//   EXPECT_EQ(mci_cmp('a', 'a'), __mci_cmp('a', 'a'));
//   EXPECT_EQ(mci_cmp('a', 'b'), __mci_cmp('a', 'b'));
// }

// TEST(mapObserver, value_comp) {
//   std::map<char,int> mci_1;
//   std::map<char,int>::value_compare mci_cmp = mci_1.value_comp();
//   mci_1['a'] = 20;
//   mci_1['b'] = 40;
//   mci_1['c'] = 60;
//   mci_1['d'] = 80;
//   mci_1['e'] = 100;
//   std::map<char,int>::iterator it = mci_1.begin();
//   EXPECT_EQ(mci_cmp(*it, *it++), 1);
//   EXPECT_EQ(mci_cmp(*it, *it), 0);
// }

// TEST(mapOperations, find) {
//   std::map<char,int> mci_1;
//   std::map<char,int>::iterator it;
//   mci_1['a'] = 50;
//   mci_1['b'] = 100;
//   mci_1['c'] = 150;
//   mci_1['d'] = 200;
//   it = mci_1.find('b');
//   EXPECT_EQ((*it).second, 100);
// }

// TEST(mapOperations, count) {
//   std::map<char,int> mci_1;
//   char ch;
//   mci_1['a'] = 101;
//   mci_1['c'] = 202;
//   mci_1['f'] = 303;
//   EXPECT_EQ(mci_1.count('a'), 1);
//   EXPECT_EQ(mci_1.count('e'), 0);
// }

// TEST(mapOperations, lower_upper_bound) {
//   std::map<char,int> mci_1;
//   std::map<char,int>::iterator itlow,itup;
//   mci_1['a'] = 20;
//   mci_1['b'] = 40;
//   mci_1['c'] = 60;
//   mci_1['d'] = 80;
//   mci_1['e'] = 100;
//   itlow = mci_1.lower_bound ('b');  // itlow points to b
//   EXPECT_EQ(itlow, mci_1.find('b'));
//   itup = mci_1.upper_bound ('d');   // itup points to e (not d!)
//   EXPECT_EQ(--itup, mci_1.find('d'));
// }

// TEST(mapOperations, equal_range) {
//   std::map<char,int> mci_1;
//   mci_1['a'] = 20;
//   mci_1['b'] = 40;
//   mci_1['c'] = 60;
//   mci_1['d'] = 80;
//   mci_1['e'] = 100;
//   std::pair<std::map<char,int>::iterator, std::map<char, int>::iterator> ret;
//   ret = mci_1.equal_range('b');
//   EXPECT_EQ(ret.first->first, 'b');
//   EXPECT_EQ(ret.second->first, 'c');
// }

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}