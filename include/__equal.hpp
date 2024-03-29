#ifndef __EQUAL_HPP_
#define __EQUAL_HPP_

namespace ft {

// equality (1)
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
// predicate (2)
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
           BinaryPredicate pred);

template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  while (first1 != last1) {
    if (!(*first1 == *first2)) {
      return false;
    } else {
      ++first1;
      ++first2;
    }
  }

  return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
           BinaryPredicate pred) {
  while (first1 != last1) {
    if (!pred(*first1, *first2)) {
      return false;
    } else {
      ++first1;
      ++first2;
    }
  }

  return true;
}

}  // namespace ft

#endif  // __EQUAL_HPP_
