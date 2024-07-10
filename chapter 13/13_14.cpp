#include <string>
#include <iostream>
#include <vector>

class MyClass {
public:
    MyClass() {}
    ~MyClass() {}

    void* operator new(size_t size, const std::string info) {
        allocationInfo.push_back(info);
        return ::operator new(size);
    }

    void* operator new(size_t size) {
        return ::operator new(size);
    }

    static std::vector<std::string> allocationInfo; 
};

std::vector<std::string> MyClass::allocationInfo;

int main() {
    MyClass* obj1 = new (__FILE__ ":" + std::to_string(__LINE__)) MyClass;
    MyClass* obj2 = new (__FILE__ ":" + std::to_string(__LINE__)) MyClass;

    for (const auto& info : MyClass::allocationInfo) {
        std::cout << "Allocation info: " << info << std::endl;
    }

    delete obj1;
    delete obj2;

    return 0;
}