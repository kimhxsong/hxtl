#ifndef STACK_HPP_
#define STACK_HPP_

#include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> > class stack
{
 public:
  typedef T value_type;
  typedef Container container_type;
  typedef size_t size_type;

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
};

template <class T, class Container>
bool operator==(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs);

template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs);

template <class T, class Container>
bool operator<(const ft::stack<T, Container>& lhs,
               const ft::stack<T, Container>& rhs);

template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs);

template <class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs,
               const ft::stack<T, Container>& rhs);

template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs,
                const ft::stack<T, Container>& rhs);


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

}  // namespace ft

#endif  // STACK_HPP_
