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

class C : public B {
    A a;
public:
    C(int ii) : B(ii), a(ii) {
        cout << "Constructor of class C" << endl;
    }
    ~C() {
        cout << "Destructor of class C" << endl;
    }
    void f() const {
        a.f();
        B::f();
    }
};

class D : public B {
    C c;
public:
    D(int ii) : B(ii), c(ii) {
        cout << "Constructor of class D" << endl;
    }
    ~D() {
        cout << "Destructor of class D" << endl;
    }
    void f() const {
        c.f();
        B::f();
    }
};

int main() {
    D d(47);
    return 0;
}