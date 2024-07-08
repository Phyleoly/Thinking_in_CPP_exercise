#include <iostream>
#include <string>

class MyClass {
    std::string message;

public:
    MyClass(std::string str) : message(str) {}

    MyClass(const MyClass& other, const std::string& presetValue = "op=call.") : message(presetValue) {
        std::cout << "Copy constructor called with preset value: " << presetValue << std::endl;
    }

    void showCopyConstructor() {
        std::cout << "Message in this object: " << message << std::endl;
    }
};

void testCopyConstructor(MyClass obj) {
    obj.showCopyConstructor();
}

int main() {
    MyClass original("original message");

    testCopyConstructor(original);

    return 0;
}