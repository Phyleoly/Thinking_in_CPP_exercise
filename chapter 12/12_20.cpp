#include <iostream>

class MyClass {
    int data;

public:
    MyClass(int d) : data(d) {}

    int getData() const { return data; }

    friend MyClass& operator=(MyClass& lhs, const MyClass& rhs) {
        lhs.data = rhs.data;
        return lhs;
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2(99);

    obj1 = obj2;  

    std::cout << "obj1 data after assignment: " << obj1.getData() << std::endl;

    return 0;
}