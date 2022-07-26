#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector>

namespace ft {

template <class T, class Container = std::vector<T> >
class stack {
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

 private:
  container_type c;
};

}  // namespace ft

template <class T, class Container >
bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

#include "stack.tpp"

#endif  // STACK_HPP_
