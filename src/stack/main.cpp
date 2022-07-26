#include "stack.hpp"

int main() {
  ft::stack<int> mystack;
  ft::stack<int> mystack2(mystack);
  ft::stack<int> mystack3;
  mystack3 = mystack2;
}