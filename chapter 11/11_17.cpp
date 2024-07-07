#include <iostream>

class MyClass {
private:
    double* val;
public:
    MyClass(double data) {
        val = new double;
        *val = data;
    }

    ~MyClass() {
        std::cout << *val << std::endl;
        *val = -1;
        delete val;
        val = nullptr;
    }

    MyClass(const MyClass& myClass) {
        val = new double;
        *val = *myClass.val;
    }
};

void f(MyClass myClass) {}

int main() {
    MyClass myClass(1.3);
    f(myClass);

    return 0;
}