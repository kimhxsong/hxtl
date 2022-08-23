/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_unittest.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:36:59 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/08/04 11:55:50 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "gtest/gtest.h"

#if 1
namespace ft = std;
#else
#include "../map.hpp"
#endif

// MAP_CONSTRUCTOR
// explicit map (const key_compare& comp = key_compare(),
//              const allocator_type& alloc = allocator_type());
TEST(map_constructor, empty__1__)
{
  ft::map<char, int> __ft__map;

  EXPECT_EQ(__ft__map.size(), 0);
}

// template <class InputIterator>
// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
//     const allocator_type& alloc = allocator_type());
TEST(map_constructor, range__2__)
{
  std::vector<std::pair<char, int> > __std__vec_with_pair;
  for (int i = 33; i < 127; i++)
  {
    __std__vec_with_pair.push_back(std::make_pair(static_cast<char>(i), i));
  }

  ft::map<char, int> __ft__map(__std__vec_with_pair.begin(),
                               __std__vec_with_pair.end());

  EXPECT_EQ(__ft__map.size(), 127 - 33);
}

// map(const map& x);
TEST(map_constructor, copy__3__)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int> __ft__map2(__ft__map);

  EXPECT_EQ(__ft__map.size(), __ft__map2.size());
}

TEST(map_operator, assign)
{
  std::vector<std::pair<char, int> > __std__vec_with_pair;
  for (int i = 33; i < 127; i++)
  {
    __std__vec_with_pair.push_back(std::make_pair(static_cast<char>(i), i));
  }

  ft::map<char, int> __ft__map(__std__vec_with_pair.begin(),
                               __std__vec_with_pair.end());
  ft::map<char, int> __ft__map2(__ft__map);

  EXPECT_EQ(__ft__map.size(), __ft__map2.size());
}

// GETTER
TEST(map_get_allocator, get_allocator)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::allocator_type __std__alloc = __ft__map.get_allocator();
}

// ITERATORS
TEST(map_iterator, bidirectional_iterator)
{
  ft::map<std::string, int> __ft__map;
  __ft__map["a"] = 10;
  __ft__map["b"] = 20;
  __ft__map["c"] = 30;
  __ft__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  ft::map<std::string, int>::iterator __ft__it = __ft__map.begin();
  ft::map<std::string, int>::iterator __ft__it2(__ft__it);
  ft::map<std::string, int>::iterator __ft__it3;
  __ft__it3 = __ft__it2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__ft__it2 == __ft__it3, true);
  EXPECT_EQ(__ft__it2 != __ft__map.end(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__ft__it2).second == 10, true);
  EXPECT_EQ(__ft__map.begin()->first.size() == std::string("a").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
  __ft__it2->second = 100;
  EXPECT_EQ(__ft__it2->second == 100, true);
  __ft__it2->second = 10;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__ft__it;
  __ft__it++;
  EXPECT_EQ((*__ft__it++).second == 30, true);
  EXPECT_EQ((__ft__it)->second == 40, true);

  --__ft__it;
  __ft__it--;
  EXPECT_EQ((*__ft__it--).second == 20, true);
  EXPECT_EQ((__ft__it)->second == 10, true);
}

// ITERATORS
TEST(map_iterator, const_iterator)
{
  ft::map<std::string, int> __ft__map;
  __ft__map["a"] = 10;
  __ft__map["b"] = 20;
  __ft__map["c"] = 30;
  __ft__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  ft::map<std::string, int>::const_iterator __ft__cit = __ft__map.begin();
  ft::map<std::string, int>::const_iterator __ft__cit2(__ft__cit);
  ft::map<std::string, int>::const_iterator __ft__cit3;
  __ft__cit3 = __ft__cit2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__ft__cit2 == __ft__cit3, true);
  EXPECT_EQ(__ft__cit2 != __ft__map.end(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__ft__cit2).second == 10, true);
  EXPECT_EQ(__ft__map.begin()->first.size() == std::string("a").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
  //   __ft__cit2->second = 100; // !NOTE: Does Not Compile.
  //   EXPECT_EQ(__ft__cit2->second == 100, true);
  //   __ft__cit2->second = 10;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__ft__cit;
  __ft__cit++;
  EXPECT_EQ((*__ft__cit++).second == 30, true);
  EXPECT_EQ((__ft__cit)->second == 40, true);

  --__ft__cit;
  __ft__cit--;
  EXPECT_EQ((*__ft__cit--).second == 20, true);
  EXPECT_EQ((__ft__cit)->second == 10, true);
}

TEST(map_iterator, reverse_iterator)
{
  ft::map<std::string, int> __ft__map;
  __ft__map["a"] = 10;
  __ft__map["b"] = 20;
  __ft__map["c"] = 30;
  __ft__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  ft::map<std::string, int>::reverse_iterator __ft__rit = __ft__map.rbegin();
  ft::map<std::string, int>::reverse_iterator __ft__rit2(__ft__rit);
  ft::map<std::string, int>::reverse_iterator __ft__rit3;
  __ft__rit3 = __ft__rit2;

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__ft__rit2 == __ft__rit3, true);
  EXPECT_EQ(__ft__rit2 != __ft__map.rend(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__ft__rit2).second == 40, true);
  EXPECT_EQ(__ft__map.rbegin()->first.size() == std::string("d").size(), true);

  // For mutable iterators (non-constant iterators):
  // Can be dereferenced as an lvalue (if in a dereferenceable state).
  __ft__rit2->second = 400;
  EXPECT_EQ(__ft__rit2->second == 400, true);
  __ft__rit2->second = 40;

  // Can be incremented (if in a dereferenceable state).
  // The result is either also dereferenceable or a past-the-end iterator.
  // Two iterators that compare equal, keep comparing equal after being both increased.
  ++__ft__rit;
  __ft__rit++;
  EXPECT_EQ((*__ft__rit++).second == 20, true);
  EXPECT_EQ((__ft__rit)->second == 10, true);

  --__ft__rit;
  __ft__rit--;
  EXPECT_EQ((*__ft__rit--).second == 30, true);
  EXPECT_EQ((__ft__rit)->second == 40, true);
}

// ITERATORS
TEST(map_iterator, const_reverse_iterator)
{
  ft::map<std::string, int> __ft__map;
  __ft__map["a"] = 10;
  __ft__map["b"] = 20;
  __ft__map["c"] = 30;
  __ft__map["d"] = 40;

  // Is default-constructible, copy-constructible, copy-assignable and destructible
  ft::map<std::string, int>::const_reverse_iterator __std__crit =
      __ft__map.rbegin();
  ft::map<std::string, int>::const_reverse_iterator __std__crit2(__std__crit);
  ft::map<std::string, int>::const_reverse_iterator __std__crit3;
  __std__crit3 = __std__crit2;
  ft::map<std::string, int>::const_reverse_iterator __std__crit4(
      __ft__map.begin());  // copy iterator to reverse_iterator

  // Can be compared for equivalence using the equality/inequality operators
  EXPECT_EQ(__std__crit2 == __std__crit3, true);
  EXPECT_EQ(__std__crit2 != __ft__map.rend(), true);

  // Can be dereferenced as an rvalue (if in a dereferenceable state).
  EXPECT_EQ((*__std__crit2).second == 40, true);
  EXPECT_EQ(__ft__map.rbegin()->first.size() == std::string("a").size(), true);

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

TEST(map_iterator, convertible_to_const)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::iterator __ft__it(__ft__map.begin());
  ft::map<char, int>::const_iterator __ft__cit(__ft__it);
  ft::map<char, int>::const_iterator __ft__cit2(__ft__cit);
  // ft::map<char,int>::iterator __ft__it2(__ft__cit2);  // !NOTE: Does Not Compile

  ft::map<char, int>::reverse_iterator __ft__rit(__ft__it);
  ft::map<char, int>::const_reverse_iterator __std__crit(__ft__rit);
  ft::map<char, int>::const_reverse_iterator __std__crit2(__std__crit);
  ft::map<char, int>::const_reverse_iterator __std__crit3(__ft__it);
  ft::map<char, int>::const_reverse_iterator __std__crit4(__ft__cit);
  // ft::map<char,int>::reverse_iterator __ft__rit2(__std__crit); !NOTE: Does Not Compile
}

TEST(map_iterator, relational_opeartors)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::iterator __ft__it(__ft__map.begin());
  ft::map<char, int>::const_iterator __ft__cit(__ft__it);
  ft::map<char, int>::const_iterator __ft__cit2(__ft__cit);
  // ft::map<char,int>::iterator __ft__it2(__ft__cit2);  // !NOTE: Does Not Compile

  ft::map<char, int>::reverse_iterator __ft__rit(__ft__it);
  ft::map<char, int>::const_reverse_iterator __std__crit(__ft__rit);
  ft::map<char, int>::const_reverse_iterator __std__crit2(__std__crit);
  ft::map<char, int>::const_reverse_iterator __std__crit3(__ft__it);
  ft::map<char, int>::const_reverse_iterator __std__crit4(__ft__cit);
  // ft::map<char,int>::reverse_iterator __ft__rit2(__std__crit); !NOTE: Does Not Compile

  bool __b;
  __b = __ft__it == __ft__map.begin();
  __b = __ft__cit == __ft__map.begin();
  __b = __ft__rit == __ft__map.rbegin();
  __b = __std__crit == __ft__map.rbegin();

  __b = __ft__it != __ft__map.begin();
  __b = __ft__cit != __ft__map.begin();
  __b = __ft__rit != __ft__map.rbegin();
  __b = __std__crit != __ft__map.rbegin();

  // __b = __ft__it < __ft__map.begin(); // !NOTE: Does Not Compile
  // __b = __ft__cit < __ft__map.begin();s // !NOTE: Does Not Compile
  // __b = __ft__rit < __ft__map.rbegin(); // !NOTE: Does Not Compile
  // __b = __std__crit < __ft__map.rbegin(); // !NOTE: Does Not Compile

  // __b = __ft__it == __ft__map.rbegin();  // !NOTE: Does Not Compile
  // __b = __ft__cit == __ft__map.rbegin();  // !NOTE: Does Not Compile
  // __b = __ft__rit == __ft__map.begin();  // !NOTE: Does Not Compile
  // __b = __std__crit == __ft__map.begin();  // !NOTE: Does Not Compile
}

TEST(map_capacity, capacity)
{
  ft::map<char, int> __ft__map;
  EXPECT_EQ(__ft__map.empty(), true);
  EXPECT_EQ(__ft__map.size(), 0);

  // This is the maximum potential size the container can reach due to known
  // system or library implementation limitations, but the container is by no
  // means guaranteed to be able to reach that size: it can still fail to allocate
  //  storage at any point before that size is reached.
  // __ft__map.max_size();  //
}

TEST(map_operator, element_access)
{
  ft::map<std::string, int> __ft__map;
  // mapped_type& operator[] (const key_type& k);
  // (*((this->insert(make_pair(k,mapped_type()))).first)).second
  __ft__map["answer"] = 42;
  EXPECT_EQ(__ft__map["answer"], 42);
}

TEST(map_insert, single_element__1)
{
  ft::map<std::string, int> __ft__map;
  // pair<iterator,bool> insert (const value_type& val);
  __ft__map.insert(
      std::pair<std::string, int>("zero", 0));  // single element(1)
}

TEST(map_insert, with_hint__2)
{
  ft::map<std::string, int> __ft__map;

  std::pair<std::map<std::string, int>::iterator, bool> ret;
  // iterator insert (iterator position, const value_type& val);
  ret = __ft__map.insert(
      std::pair<std::string, int>("answer", 42));  // with hint(2)
  EXPECT_EQ(ret.second, true);
}

TEST(map_insert, range__3)
{
  std::vector<std::pair<std::string, int> > __std__vec;
  __std__vec.push_back(std::make_pair("answer", 42));

  ft::map<std::string, int> __ft__map;
  // template <class InputIterator>
  // void insert (InputIterator first, InputIterator last);
  __ft__map.insert(__std__vec.begin(), __std__vec.end());  // range(3)
}

TEST(map_erase, __1)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::iterator it;
  __ft__map['a'] = 10;
  __ft__map['b'] = 20;
  __ft__map['c'] = 30;
  __ft__map['d'] = 40;
  it = __ft__map.begin();
  // void erase (iterator position);
  __ft__map.erase(it);  // erasing by iterator
}

TEST(map_erase, __2)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::iterator it;
  __ft__map['a'] = 10;
  __ft__map['b'] = 20;
  __ft__map['c'] = 30;
  __ft__map['d'] = 40;
  // size_type erase (const key_type& k);
  __ft__map.erase('c');  // erasing by key
}

TEST(map_erase, __3)
{
  ft::map<char, int> __ft__map;
  __ft__map['a'] = 10;
  __ft__map['b'] = 20;
  __ft__map['c'] = 30;
  __ft__map['d'] = 40;
  ft::map<char, int>::iterator it = __ft__map.find('d');
  //  void erase (iterator first, iterator last);
  __ft__map.erase(it, __ft__map.end());  // erasing by range
}

TEST(map_swap, swap)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int> __ft__map2;
  __ft__map['x'] = 100;
  __ft__map['y'] = 200;
  __ft__map2['a'] = 100;
  __ft__map2['b'] = 200;
  __ft__map2['c'] = 300;
  ft::map<char, int> __ft__map__copied(__ft__map);
  __ft__map2.swap(__ft__map);
  EXPECT_EQ(__ft__map2 == __ft__map__copied, true);
}

TEST(map_clear, clear)
{
  ft::map<char, int> __ft__map;
  __ft__map['x'] = 100;
  __ft__map['y'] = 200;
  __ft__map.clear();
  EXPECT_EQ(__ft__map.size(), 0);

  __ft__map['x'] = 1100;
  __ft__map['y'] = 2200;
  EXPECT_EQ(__ft__map['x'], 1100);
  EXPECT_EQ(__ft__map['y'], 2200);
}

// template < class Key,                                     // map::key_type
//            class T,                                       // map::mapped_type
//            class Compare = less<Key>,                     // map::key_compare
//            class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
//            > class map;
TEST(map_key_compare, key_compare)
{
  ft::map<char, int> __ft__map;
  // key_compare key_comp() const;
  ft::map<char, int>::key_compare __ft__map__cmp = __ft__map.key_comp();

  EXPECT_EQ(__ft__map__cmp('a', 'b'), true);
}

// template <class Key, class T, class Compare, class Alloc>
// class map<Key,T,Compare,Alloc>::value_compare
// {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
//   friend class map;
// protected:
//   Compare comp;
//   value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
// public:
//   typedef bool result_type;
//   typedef value_type first_argument_type;
//   typedef value_type second_argument_type;
//   bool operator() (const value_type& x, const value_type& y) const
//   {
//     return comp(x.first, y.first);
//   }
// }
TEST(map_value_comp, value_comp)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::value_compare __ft__map__cmp = __ft__map.value_comp();
  __ft__map['a'] = 20;
  __ft__map['b'] = 40;
  __ft__map['c'] = 60;
  __ft__map['d'] = 80;
  __ft__map['e'] = 100;
  ft::map<char, int>::iterator it = __ft__map.begin();
  ft::map<char, int>::iterator it2(it);
  EXPECT_EQ(__ft__map__cmp(*it, *it2++), false);
  EXPECT_EQ(__ft__map__cmp(*it, *it2), true);
}

TEST(map_find, find)
{
  ft::map<char, int> __ft__map;
  ft::map<char, int>::iterator it;
  __ft__map['a'] = 50;
  __ft__map['b'] = 100;
  __ft__map['c'] = 150;
  __ft__map['d'] = 200;
  it = __ft__map.find('b');
  EXPECT_EQ((*it).second, 100);
  EXPECT_EQ(__ft__map.find('e'), __ft__map.end());
}

TEST(map_find, find_const)
{
  ft::map<char, int> __ft__map;
  __ft__map['a'] = 50;
  __ft__map['b'] = 100;
  __ft__map['c'] = 150;
  __ft__map['d'] = 200;
  ft::map<char, int>::const_iterator cit = __ft__map.find('b');
  EXPECT_EQ((*cit).second, 100);
  EXPECT_EQ(__ft__map.find('e'), __ft__map.end());
}

TEST(map_count, count)
{
  ft::map<char, int> __ft__map;
  char ch;
  __ft__map['a'] = 101;
  __ft__map['c'] = 202;
  __ft__map['f'] = 303;
  // size_type count (const key_type& k) const;
  EXPECT_EQ(__ft__map.count('a'), 1);
  EXPECT_EQ(__ft__map.count('e'), 0);
}

TEST(map_lower_upper_bound, lower_upper_bound)
{
  ft::map<char, int> __ft__map;
  __ft__map['a'] = 20;
  __ft__map['b'] = 40;
  __ft__map['c'] = 60;
  __ft__map['d'] = 80;
  __ft__map['e'] = 100;
  // iterator lower_bound (const key_type& k);
  ft::map<char, int>::iterator itlow =
      __ft__map.lower_bound('b');  // itlow points to b
  EXPECT_EQ(itlow, __ft__map.find('b'));
  ft::map<char, int>::iterator itup =
      __ft__map.upper_bound('d');  // itup points to e (not d!)
  EXPECT_EQ(--itup, __ft__map.find('d'));

  ft::map<char, int>::iterator itend =
      __ft__map.upper_bound('e');  // itup points to e (not d!)
  EXPECT_EQ(itend, __ft__map.end());
  ft::map<char, int>::iterator itend2 =
      __ft__map.lower_bound('e');  // itup points to e (not d!)
  EXPECT_EQ(itend, __ft__map.end());
}

TEST(map_lower_upper_bound, lower_upper_bound_const)
{
  ft::map<char, int> __ft__map;
  __ft__map['a'] = 20;
  __ft__map['b'] = 40;
  __ft__map['c'] = 60;
  __ft__map['d'] = 80;
  __ft__map['e'] = 100;
  // const_iterator lower_bound (const key_type& k) const;
  ft::map<char, int>::const_iterator citlow =
      __ft__map.lower_bound('b');  // itlow points to b
  EXPECT_EQ(citlow, __ft__map.find('b'));
  ft::map<char, int>::const_iterator citup =
      __ft__map.upper_bound('d');  // itup points to e (not d!)
  EXPECT_EQ(--citup, __ft__map.find('d'));

  // ft::map<char,int>::const_iterator citend = __ft__map.upper_bound ('e');
  // EXPECT_EQ(citend, __ft__map.end());  // !NOTE: Does Not Compile
  // ft::map<char,int>::const_iterator citend2 = __ft__map.lower_bound ('e');
  // EXPECT_EQ(citend2, __ft__map.end());  // !NOTE: Does Not Compile
}

TEST(map_equal_range, equal_range)
{
  ft::map<char, int> __ft__map;
  __ft__map['a'] = 20;
  __ft__map['b'] = 40;
  __ft__map['c'] = 60;
  __ft__map['d'] = 80;
  __ft__map['e'] = 100;
  std::pair<std::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
  // pair<iterator,iterator>             equal_range (const key_type& k);
  ret = __ft__map.equal_range('b');
  EXPECT_EQ(ret.first->first, 'b');
  EXPECT_EQ(ret.second->first, 'c');

  ret = __ft__map.equal_range('f');
  EXPECT_EQ(ret.first, __ft__map.end());
  EXPECT_EQ(ret.second, __ft__map.end());
}

TEST(map_equal_range, equal_range_const)
{
  ft::map<char, int> __ft__map;
  __ft__map['a'] = 20;
  __ft__map['b'] = 40;
  __ft__map['c'] = 60;
  __ft__map['d'] = 80;
  __ft__map['e'] = 100;
  std::pair<std::map<char, int>::const_iterator,
            ft::map<char, int>::const_iterator>
      cret;
  // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
  cret = __ft__map.equal_range('b');
  EXPECT_EQ(cret.first->first, 'b');
  EXPECT_EQ(cret.second->first, 'c');

  cret = __ft__map.equal_range('f');
  EXPECT_EQ(cret.first, __ft__map.end());
  EXPECT_EQ(cret.second, __ft__map.end());
}

TEST(etc, etc)
{
  ft::map<char, const int> __ft__map;
  // __ft__map['a'] = static_cast<int>('a'); // !NOTE: Does Not Compile
  // __ft__map['a'] = static_cast<const int>('a'); // !NOTE: Does Not Compile
  ft::map<char, const int>::iterator it = __ft__map.begin();
  // *it = 'b';  // !NOTE: Does Not Compile
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}