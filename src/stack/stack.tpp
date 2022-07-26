#ifndef STACK_TPP_
#define STACK_TPP_

#ifndef STACK_HPP_
#error error
#endif // STACK_HPP_

#include "stack.hpp"

namespace ft {

template <class T, class Container>
stack<T, Container>::stack(const container_type& ctnr)
  : c(ctnr) {}

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

}  // namespace ft

template <class T, class Container>
bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
  return lhs.c == rhs.c;
}

template <class T, class Container>
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
  return !(lhs.c == rhs.c);
}

template <class T, class Container>
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
  return lhs.c < rhs.c;
}

template <class T, class Container>
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
  return !(rhs.c < lhs);
}

template <class T, class Container>
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
  return rhs < lhs;
}

template <class T, class Container>
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
  return !(lhs.c < rhs.c);
}

#endif // STACK_TPP
