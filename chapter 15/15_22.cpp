#include <iostream>
using namespace std;

class Base {
public:
    virtual void func(int x) {
        cout << "Base::func(int) called with " << x << endl;
    }
    virtual void func(double x) {
        cout << "Base::func(double) called with " << x << endl;
    }
    virtual void func(int x, double y) {
        cout << "Base::func(int, double) called with " << x << " and " << y << endl;
    }
};

class Derived : public Base {
public:
    void func(int x) override {
        cout << "Derived::func(int) called with " << x << endl;
    }
};

int main() {
    Derived d;

    d.func(10);         
    d.func(10.5);       
    // d.func(10, 20.5);   

    Base* b = &d;

    b->func(10);         
    b->func(10.5);       
    b->func(10, 20.5);   

    return 0;
}