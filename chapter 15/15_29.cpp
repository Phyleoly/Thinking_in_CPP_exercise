#include <iostream>

class X {
public:
    X() {
        func(); 
    }
    
    virtual void func() {
        std::cout << "X::func()" << std::endl;
    }
    
    virtual ~X() {} 
};

class Y : public X {
public:
    Y() {
        func(); 
    }
    
    void func() override {
        std::cout << "Y::func()" << std::endl;
    }
};