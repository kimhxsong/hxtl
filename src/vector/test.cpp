
// #include "vector.hpp"
#include <iostream>

#include <vector>
#include <set>
#include "vector.hpp"

// 생성자 호출 가능한지
void test_primitive_constructor() {
  { 
    std::vector<int> vec_1;
    std::vector<int> vec_2(10);
    std::vector<int> vec_3(10, 10);
    std::vector<int> vec_4(vec_3.begin(), vec_3.end());
  }
  {
    ft::vector<int> vec_1;
    ft::vector<int> vec_2(10);
    ft::vector<int> vec_3(10, 10);
    ft::vector<int>::iterator _begin = vec_2.begin();
    ft::vector<int>::iterator _end = vec_2.end();
    ft::vector<int> vec_4(_begin, _end);
  }

  { 
    std::vector<int> vec_1;
    std::vector<int> vec_2(10);
    ft::vector<int> vec_3(vec_2.begin(), vec_2.end());
  }

  { 
    ft::vector<int> vec_1;
    ft::vector<int> vec_2(10);
    std::vector<int> vec_3(vec_2.begin(), vec_2.end());
  }
}

int main() {
  test_primitive_constructor();
}
