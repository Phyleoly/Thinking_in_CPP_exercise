#include <iostream>
using namespace std;

class A {
    int i;
public:
    A(int ii) : i(ii) {
        cout << "Constructor of class A" << endl;
    }
    ~A() {
        cout << "Destructor of class A" << endl;
    }
    void f() const {}
};

class B {
    int i;
public:
    B(int ii) : i(ii) {
        cout << "Constructor of class B" << endl;
    }
    ~B() {
        cout << "Destructor of class B" << endl;
    }
    void f() const {}
};

class D {
    int i;
public:
    D(int ii) : i(ii) {
        cout << "Constructor of class D" << endl;
    }
    ~D() {
        cout << "Destructor of class D" << endl;
    }
    void f() const {}
};

class E {
    int i;
public:
    E(int ii) : i(ii) {
        cout << "Constructor of class E" << endl;
    }
    ~E() {
        cout << "Destructor of class E" << endl;
    }
    void f() const {}
};

class C : public D {
    A a;
    E e;
public:
    C(int ii) : D(ii), a(ii), e(ii) {
        cout << "Constructor of class C" << endl;
    }
    ~C() {
        cout << "Destructor of class C" << endl;
    }
    void f() const {
        a.f();
        D::f();
        e.f();
    }
};

int main() {
    C c(47);
    return 0;
}