#include <iostream>

class MyClass {
public:
    MyClass() {}
    ~MyClass() {}

    void* operator new(size_t size) {
        std::cout << "new for MyClass, size = " << size << std::endl;
        return ::operator new(size);
    }

    void operator delete(void* ptr) {
        std::cout << "delte for MyClass" << std::endl;
        ::operator delete(ptr);
    }

    void* operator new[](size_t size) {
        std::cout << "new[] for MyClass, size = " << size << std::endl;
        return ::operator new[](size);
    }

    void operator delete[](void* ptr) {
        std::cout << "delte[] for MyClass" << std::endl;
        ::operator delete[](ptr);
    }
};

int main() {
    MyClass* obj1 = new MyClass;
    delete obj1;

    std::cout << std::endl;

    MyClass* arr = new MyClass[5];
    delete[] arr;

    return 0;
}