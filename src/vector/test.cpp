
// #include "vector.hpp"
#include <iostream>

// void test_ctor() {
//     vector v;
//     vector v2(5);
//     v2.reserve(2);
//     v2.resize(100);
//     v2.resize(50);
//     std::cout << v2.max_size() << '\n';
// }

#include <vector>
#include <set>
#include "vector.hpp"

int main() {
    {
        // std::vector<int> v1;
        // for (int i = 0; i < 100; i++) {
        //     v1.push_back(i);
        // }
        // for (std::vector<int>::iterator first = v1.begin(); first != v1.end(); first++) {
        //     std::cout << *first << std::endl;
        // }
        // for (std::vector<int>::const_iterator first = v1.begin(); first != v1.end(); first++) {
        //     std::cout << *first << std::endl;
        // }
        // for (std::vector<int>::reverse_iterator first = v1.rbegin(); first != v1.rend(); first++) {
        //     std::cout << *first << std::endl;
        // }
        // for (std::vector<int>::const_reverse_iterator first = v1.rbegin(); first != v1.rend(); first++) {
        //     std::cout << *first << std::endl;
        // }
    }
    {
        ft::vector<int> v1;
        for (int i = 0; i < 100; i++) {
            v1.push_back(i);
        }
        // for (ft::vector<int>::iterator first = v1.begin(); first != v1.end(); first++) {
        //     std::cout << first << std::endl;  // TODO: 컴파일 불가능하도록 만들어야 함.
        // }
        for (ft::vector<int>::const_iterator first = v1.begin(); first != v1.end(); first++) {
            std::cout << first << std::endl;
        }
        // for (ft::vector<int>::reverse_iterator first = v1.rbegin(); first != v1.rend(); first++) {
        //     std::cout << *first << std::endl;
        // }
        for (ft::vector<int>::const_reverse_iterator first = v1.rbegin(); first != v1.rend(); first++) {
            std::cout << *first << std::endl;
        }
    }
}
