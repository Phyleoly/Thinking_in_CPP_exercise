#include <iostream>

enum ArraySize {
    Small = 5,
    Medium = 10,
    Large = 15
};

class MyClass {
private:
    const int constMember;  
    int array[Large];       

public:
    MyClass(ArraySize size, int constValue)
        : constMember(constValue) {
        switch (size) {
            case Small:
                std::cout << "Array size: Small (" << Small << ")" << std::endl;
                break;
            case Medium:
                std::cout << "Array size: Medium (" << Medium << ")" << std::endl;
                break;
            case Large:
                std::cout << "Array size: Large (" << Large << ")" << std::endl;
                break;
            default:
                std::cerr << "Invalid size!" << std::endl;
                break;
        }
    }

    void printConstMember() const {
        std::cout << "Const member value: " << constMember << std::endl;
    }
};

int main() {
    MyClass obj(Medium, 100);

    obj.printConstMember();

    return 0;
}