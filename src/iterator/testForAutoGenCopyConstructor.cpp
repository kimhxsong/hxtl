
// A Test involving the constructor of const_iterator

template <class T>
class A {
 public:
    A() {}
    A(const A<int*>& other) {}
};

int main() {
    A<int*> a0;
    A<const int*> a1(a0);
    A<const int*> a2(a1);
    // A<int*> a4(a2); // Error

    // A<int> a0;
    // A<const int> a1(a0);
    // A<const int> a2(a1);
    // A<int> a4(a2); // Error

    // int num = 3;
    // ft::random_iterator<int*> _iter(&num);
    // ft::random_iterator<const int*> c_iter(_iter);
    // ft::random_iterator<const int*> c_iter2(c_iter);
    // ft::random_iterator<const int*> c_iter3;
    // c_iter3 = c_iter2;
    // std::vector<int>::iterator it;
    // std::vector<int>::const_iterator cit(it);
    // std::vector<int>::const_iterator cit2(cit);
}


