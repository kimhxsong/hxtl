#include <vector>
#include <iostream>
#include <string>

class A {
    int num;

 public:
    A() : num(0) {
        std::cout << "ctor: default" << std::endl;
    }

    A(int num) : num(num) {
        std::cout << "ctor: conversion" << std::endl;
    }

    A(const A& other) : num(other.num) {
        std::cout << "ctor: copied" << std::endl;
    }

    ~A() {
        std::cout << "dtor" << std::endl;
    }

    A& operator=(const A& other) {
        std::cout << "oper: =" << std::endl;
        return *this;
    }
};

int main() {
    std::vector<A> testA(10, 42);
    std::cout << std::endl;
    testA.reserve(20);
    std::cout << std::endl;
    
    testA.insert(testA.end()-1, 5, 21); // 1.복사생성자 2.복사대입
    std::cout << std::endl;
}