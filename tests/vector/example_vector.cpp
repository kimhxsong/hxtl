// #include "hxtl.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "vector.hpp"

class A {
  int num;

 public:
  A() : num(0) { std::cout << "ctor: default" << std::endl; }

  A(int num) : num(num) { std::cout << "ctor: conversion" << std::endl; }

  A(const A& other) : num(other.num) { std::cout << "ctor: copied" << std::endl; }

  ~A() { std::cout << "dtor" << std::endl; }

  A& operator=(const A& other) {
    std::cout << "oper: =" << std::endl;
    return *this;
  }
};

int main() {
  std::cout << "STD1\n";
  std::vector<A> testA(10, 42);
  std::cout << std::endl;

  std::cout << "FT1\n";
  ft::vector<A> testFT(10, 42);
  std::cout << std::endl;

  std::cout << "STD2\n";
  testA.reserve(20);
  std::cout << std::endl;

  std::cout << "FT2\n";
  testFT.reserve(20);
  std::cout << std::endl;

  std::cout << "STD3\n";
  testA.insert(testA.begin() + 5, 5, 21);  // 1.복사생성자 2.복사대입
  std::cout << testA.size() << std::endl;

  std::cout << "FT3\n";
  testFT.insert(testFT.begin() + 5, 5, 21);  // 1.복사생성자 2.복사대입
  std::cout << testFT.size() << std::endl;

  std::cout << "STD4\n";
  testA.erase(testA.begin(), testA.begin() + 5);  // 1.복사대입 2.소멸자
  std::cout << std::endl;

  std::cout << "FT4\n";
  testFT.erase(testFT.begin(), testFT.begin() + 5);  // 1.복사대입 2.소멸자
  std::cout << std::endl;
}