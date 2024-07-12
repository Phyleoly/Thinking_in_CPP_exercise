#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    int f() const {
        cout << "Base::f()\n";
        return 1;
    }
    int f(string) const { return 1; }
    void g() {}

    void h(int) const { cout << "Base::h(int)\n"; }
    void h(double) const { cout << "Base::h(double)\n"; }
    void h(string) const { cout << "Base::h(string)\n"; }
};

class Derived1 : public Base {
public:
    void g() const {}

    void h(int) const { cout << "Derived1::h(int)\n"; }
};

class Derived2 : public Base {
public:
    int f() const {
        cout << "Derived2::f()\n";
        return 2;
    }
};

class Derived3 : public Base {
public:
    void f() const { cout << "Derived3::f()\n"; }
};

class Derived4 : public Base {
public:
    int f(int) const {
        cout << "Derived4::f(int)\n";
        return 4;
    }
};

int main() {
    string s("hello");
    Derived1 d1;
    int x = d1.f();
    d1.f(s);
    
    Derived2 d2;
    x = d2.f();
    
    Derived3 d3;
    
    Derived4 d4;
    x = d4.f(1);

    d1.h(1);        
    d1.h(3.14);     
    // d1.h("test");   

    return 0;
}
