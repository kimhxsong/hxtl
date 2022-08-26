#ifndef STACK_HPP_
#define STACK_HPP_

#include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
 public:
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;

  explicit stack(const container_type& ctnr = container_type());
  ~stack();

  value_type& top();
  const value_type& top() const;

  bool empty() const;
  size_type size() const;

  void push(const value_type& val);
  void pop();

 protected:
  container_type c;

 private:
  template <class _T, class _Ccontainer>
  friend bool operator==(const ft::stack<_T, _Ccontainer>& lhs,
                         const ft::stack<_T, _Ccontainer>& rhs);
  template <class _T, class _Ccontainer>
  friend bool operator!=(const ft::stack<_T, _Ccontainer>& lhs,
                         const ft::stack<_T, _Ccontainer>& rhs);
  template <class _T, class _Ccontainer>
  friend bool operator<(const ft::stack<_T, _Ccontainer>& lhs,
                        const ft::stack<_T, _Ccontainer>& rhs);
  template <class _T, class _Ccontainer>
  friend bool operator<=(const ft::stack<_T, _Ccontainer>& lhs,
                         const ft::stack<_T, _Ccontainer>& rhs);
  template <class _T, class _Ccontainer>
  friend bool operator>(const ft::stack<_T, _Ccontainer>& lhs,
                        const ft::stack<_T, _Ccontainer>& rhs);
  template <class _T, class _Ccontainer>
  friend bool operator>=(const ft::stack<_T, _Ccontainer>& lhs,
                         const ft::stack<_T, _Ccontainer>& rhs);
};

template <class T, class Container>
stack<T, Container>::stack(const container_type& ctnr) : c(ctnr) {}

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
typename stack<T, Container>::value_type& stack<T, Container>::top() {
  return c.back();
}

template <class T, class Container>
const typename stack<T, Container>::value_type& stack<T, Container>::top() const {
  return c.back();
}

template <class T, class Container>
bool stack<T, Container>::empty() const {
  return c.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
  return c.size();
}

template <class T, class Container>
void stack<T, Container>::push(const value_type& val) {
  c.push_back(val);
}

template <class T, class Container>
void stack<T, Container>::pop() {
  c.pop_back();
}

template <class T, class Container>
bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
  return lhs.c == rhs.c;
}

template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
  return !(lhs.c == rhs.c);
}

template <class T, class Container>
bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
  return lhs.c < rhs.c;
}

template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
  return !(rhs.c < lhs.c);
}

template <class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
  return rhs < lhs;
}

template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
  return !(lhs.c < rhs.c);
}

}  // namespace ft

#endif  // STACK_HPP_
