#ifndef PAIR_TPP_
#define PAIR_TPP_

#ifndef PAIR_HPP_
#error __FILE__ should only be included from myclass.hpp.
#endif // PAIR_HPP_

#include "pair.hpp"

namespace ft {

template<class T1, class T2>
pair<T1 ,T2>::pair()
  : first(),
    second() {}

template<class T1, class T2>
pair<T1,T2>::pair(const first_type& x, const second_type& y)
  : first(x),
    second(y) {}

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

}  // namespace ft

#endif  // PAIR_TPP_
