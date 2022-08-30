#ifndef __PAIR_HPP_
#define __PAIR_HPP_

namespace ft {

template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  first_type first;
  second_type second;

  pair() : first(), second() {}

  pair(const first_type& x, const second_type& y) : first(x), second(y) {}

  pair(const pair<T1, T2>& pr) : first(pr.first), second(pr.second) {}

  template <class U1, class U2>
  pair(const pair<U1, U2>& other) : first(other.first), second(other.second) {}

  pair& operator=(const pair& pr) {
    if (*this != pr) {
      this->first = pr.first;
      this->second = pr.second;
    }

    return *this;
  }

  ~pair() {}
};

//
// Non Member Functions
//
template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return pair<T1, T2>(x, y);
}

template <class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return !(lhs < rhs);
}

}  // namespace ft

#endif  // __PAIR_HPP_
