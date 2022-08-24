#ifndef __LEXICOGRAPHICAL_COMPARE_HPP_
#define __LEXICOGRAPHICAL_COMPARE_HPP_

namespace ft {

// default (1)
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                             InputIterator2 last2);
// custom (2)
template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                             InputIterator2 last2, Compare comp);

// The elements are compared using operator< for the first version, and comp for
// the second.
//
// Two elements, a and b are considered equivalent if (!(a<b) && !(b<a)) or
// if (!comp(a,b) && !comp(b,a)).
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                             InputIterator2 last2) {
  while (first1 != last1) {
    if (first2 == last2 || *first2 < *first1) {
      return false;
    } else if (*first1 < *first2) {
      return true;
    } else {
      ++first1;
      ++first2;
    }
  }
  return first2 != last2;
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                             InputIterator2 last2, Compare comp) {
  while (first1 != last1) {
    if (first2 == last2 || comp(*first2, *first1)) {
      return false;
    } else if (comp(*first1, *first2)) {
      return true;
    } else {
      ++first1;
      ++first2;
    }
  }
  return first2 != last2;
}

}  // namespace ft

#endif  // __LEXICOGRAPHICAL_COMPARE_HPP_
