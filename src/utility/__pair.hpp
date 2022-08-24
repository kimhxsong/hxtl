#ifndef __PAIR_HPP_
#define __PAIR_HPP_

namespace ft
{

template <class T1, class T2> struct pair;

template <class T1, class T2> pair<T1, T2> make_pair(T1 x, T2 y);

// std::relational operators (pair)
template <class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
template <class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
template <class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
template <class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
template <class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
template <class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);

template <class T1, class T2> struct pair
{
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;

  pair();                                           // default
  pair(const pair& pr);                             // copy constructor
  pair(const first_type& a, const second_type& b);  // initialization

  // implicitly declared:
  pair& operator=(const pair& pr);  // copy operator
};

template <class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y) {
  return pair<T1,T2>(x, y);
}

template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
  return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
  return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
  return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
  return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
  return !(lhs < rhs);
}

template <class T1, class T2>
pair<T1,T2>::pair()
  : first(),
    second() {}

template <class T1, class T2>
pair<T1,T2>::pair(const first_type& x, const second_type& y)
  : first(x),
    second(y) {}

template <class T1, class T2>
pair<T1,T2>::pair(const pair<T1,T2>& pr)
  : first(pr.first),
    second(pr.second) {}

template <class T1, class T2>
pair<T1,T2>& pair<T1,T2>::operator=(const pair<T1,T2>& pr) {
  if (*this != pr) {
    this->first = pr.first;
    this->second = pr.second;
  }
  return *this;
}

}  // namespace ft

#endif  // __PAIR_HPP_
