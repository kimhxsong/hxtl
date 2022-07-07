#ifndef UTILITY_PAIR_TPP_
#define UTILITY_PAIR_TPP_

#ifndef UTILITY_PAIR_HPP_
#error __FILE__ should only be included from myclass.hpp.
#endif // UTILITY_PAIR_HPP_

namespace ft {

template<class T1, class T2>
pair<T1,T2>::pair()
  : first(),
    second() {}

template<class T1, class T2>
pair<T1,T2>::pair(const first_type& a, const second_type& b)
  : first(a),
    second(b) {}

template<class T1, class T2>
pair<T1,T2>::pair(const pair<T1,T2>& pr)
  : first(pr.first),
    second(pr.second) {}

template<class T1, class T2>
pair<T1,T2>& pair<T1,T2>::operator=(const pair& pr) {
  return make_pair<T1,T2>(pr.first, pr.second);
}

template <class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y) {
  return pair<T1,T2>::pair(x, y);
}

}  // ft::

#endif  // UTILITY_PAIR_TPP_
