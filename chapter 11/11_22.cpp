#include <iostream>

class X {
public:
    X(int value) : data(value) {
        std::cout << "Constructor called with value: " << value << std::endl;
    }

    X* clone() const {
        return new X(*this); 
    }

    int getData() const {
        return data;
    }

private:
    int data;

    X(const X& other) {}
};

void modifyAndDestroy(const X& obj) {
    X* copy = obj.clone();
    delete copy;
}

int main() {
    X original(42); 

    modifyAndDestroy(original); 

    return 0;
}
