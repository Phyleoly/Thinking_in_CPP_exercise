#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base1()\n";
        f();
    }
    virtual void f() { cout << "Base::f()\n"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "~Derived()\n"; f(); }
    void f() { cout << "Derived::f()\n"; }
};

class MoreDerived : public Derived {
public:
    ~MoreDerived() { cout << "~MoreDerived()\n"; f(); }
    void f() { cout << "MoreDerived::f()\n"; }
};

int main() {
    Base* bp = new MoreDerived; // Upcast
    delete bp;
}