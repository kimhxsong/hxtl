#ifndef UTILITY_PAIR_HPP_
#define UTILITY_PAIR_HPP_



namespace ft {

template<class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;

  pair();  // default
  pair(const pair& pr);  // copy constructor
  pair(const first_type& a, const second_type& b);  // initialization

  pair& operator=(const pair& pr);  // copy operator
};

template <class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y);

}  // ft::

#include "utility_pair.tpp"

#endif  // UTILITY_PAIR_HPP_
