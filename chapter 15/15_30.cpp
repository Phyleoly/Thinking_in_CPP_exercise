#include <iostream>

class X {
public:
    virtual void func() {
        std::cout << "X::func()" << std::endl;
    }
};

class Y : public X {
public:
    void func() override {
        std::cout << "Y::func()" << std::endl;
    }
};

void testVirtualCall(X obj) {
    obj.func(); // 虚函数调用
}

int main() {
    Y y;
    testVirtualCall(y); 

    return 0;
}