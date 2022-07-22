#include <iostream>
#include <vector>

class A {
 public:
    A() {
        std::cout << "A default" << std::endl;
    }
    A(int n) : n(n) {
        std::cout << "A constructor: " << this->n << std::endl;
    }
    A(const A& other) : n(other.n) {
        std::cout << "A copied: " << this->n << std::endl;
    } 
    virtual ~A() {
        std::cout << "A destructor: " << this->n << std::endl;
    }
    void doSomething() {}
    int n;
};

class B : public A {
 public:
    B() {
        std::cout << "B default" << std::endl;
    }
    B(int n) : n(n) {
        std::cout << "B constructor: " << this->n << std::endl;
    }
    virtual ~B() {
        std::cout << "B destructor: " << this->n << std::endl;
    }
    int n;
};

int main() {
{   
    std::vector<A> alist(10);  // 기본 생성자 호출 10회, 사이즈 10.
    alist.reserve(20);  // 소멸자 호출 10회, 생성자 호출 안함.
    std::cout << std::endl;
}  // 소멸자 호출 10회

{   
    std::vector<A> alist(10, 5);  // 5 -> A(5), 암시적 생성자 호출. 소멸자 호출.
    alist.reserve(20);  // 소멸자 호출 10회, 생성자 호출 안함.
    std::cout << std::endl;
}  // 소멸자 호출 10회

{   
    std::vector<B> blist(10, 5);
    blist.reserve(20);
    std::cout << std::endl;
}

{   
    std::vector<A> blist(10, 5);
    blist.reserve(20);
    std::cout << std::endl;
}

}
