
template <class T>
class node {
 public:
  node() {}
  T data;
};

template <class T, class Node>
class MyIterator {
 public:
  typedef T value_type;
  typedef Node node_type;
  MyIterator() {}
  MyIterator(const MyIterator<T, node<T> >& other) : ptr(other.ptr) {}
  Node* ptr;
};

template <class T>
class Container {
 public:
  typedef MyIterator<T, node<T> > iterator;
  typedef MyIterator<T, const node<T> > const_iterator;
};

#include <map>

int main() {
  Container<int>::iterator it;
  Container<int>::iterator it2(it);
  Container<int>::const_iterator cit;
  Container<int>::const_iterator cit2(cit);
  Container<int>::const_iterator cit3(it);
  std::map<int, int> mymap;
  std::map<int, int>::iterator myit;
}