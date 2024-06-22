#include <iostream>

class MyClass {
public:
    int publicVar1;
    double publicVar2;

    void showMap() {
        std::cout << "Public variable 1: " << &publicVar1 << std::endl;
        std::cout << "Public variable 2: " << &publicVar2 << std::endl;
        std::cout << "Private variable 1: " << &privateVar1 << std::endl;
        std::cout << "Private variable 2: " << &privateVar2 << std::endl;
        std::cout << "Protected variable 1: " << &protectedVar1 << std::endl;
        std::cout << "Protected variable 2: " << &protectedVar2 << std::endl;
    }

private:
    int privateVar1;
    double privateVar2;

protected:
    int protectedVar1;
    double protectedVar2;
};

int main() {
    MyClass obj;

    obj.showMap();

    return 0;
}