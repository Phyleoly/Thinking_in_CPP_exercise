#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor: calling func() -> ";
        func(); 
    }
    virtual void func() const {
        cout << "Base::func()" << endl;
    }
    void callFunc() const {
        cout << "Base::callFunc(): calling func() -> ";
        func(); 
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    void func() const override {
        cout << "Derived::func()" << endl;
    }
};

int main() {
    cout << "Creating Derived object d:" << endl;
    Derived d;
    cout << "\nCalling d.callFunc():" << endl;
    d.callFunc();

    return 0;
}