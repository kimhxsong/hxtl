
#include "vector.hpp"
#include <iostream>

void test_ctor() {
    vector v;
    vector v2(5);
    v2.reserve(2);
    v2.resize(100);
    v2.resize(50);
    std::cout << v2.max_size() << '\n';
}

#include <vector>

int main() {
    test_ctor();
    vector v;
    std::cout << v.capacity() << std::endl;
    v.push_back(1);
    std::cout << v.capacity() << std::endl;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    std::cout << v.capacity() << std::endl;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    std::cout << v.capacity() << std::endl;
    // system("leaks a.out");
}