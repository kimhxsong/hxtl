#ifndef UTILITY_PAIR_HPP_
#define UTILITY_PAIR_HPP_

namespace ft {

template<class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;

// https://en.cppreference.com/w/cpp/utility/pair/pair
  pair(T1 _first, T2 _second)
    : first(_first),
      second(_second) {}

  operator=(T1 )

};

template<class T1, class T2>
pair<T1,T2> make_pair(T1 t, T2 u) {

}

}  // ft::

#endif  // UTILITY_PAIR_HPP_
