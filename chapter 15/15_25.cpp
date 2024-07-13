#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual ~Base() {}
    
    virtual Base* clone() const = 0;
    
    virtual void speak() const = 0;
};

class Derived1 : public Base {
public:
    Derived1* clone() const override {
        return new Derived1(*this);
    }
    
    void speak() const override {
        cout << "I am Derived1" << endl;
    }
};

class Derived2 : public Base {
public:
    Derived2* clone() const override {
        return new Derived2(*this);
    }
    
    void speak() const override {
        cout << "I am Derived2" << endl;
    }
};

int main() {
    Derived1 d1;
    Derived2 d2;
    
    Base* b1 = &d1;
    Base* b2 = &d2;
    
    Base* clone1 = b1->clone();
    Base* clone2 = b2->clone();
    
    cout << "Original: ";
    b1->speak();
    cout << "Cloned: ";
    clone1->speak();
    
    cout << "Original: ";
    b2->speak();
    cout << "Cloned: ";
    clone2->speak();
    
    delete clone1;
    delete clone2;
    
    return 0;
}