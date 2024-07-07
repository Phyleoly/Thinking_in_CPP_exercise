#include <iostream>

class SimpleClass {
public:
    SimpleClass() {
        std::cout << "SimpleClass Default Constructor" << std::endl;
    }

    SimpleClass(const SimpleClass& other) {
        std::cout << "SimpleClass Copy Constructor" << std::endl;
    }

    SimpleClass& operator=(const SimpleClass& other) {
        std::cout << "SimpleClass Assignment Operator" << std::endl;
        return *this;
    }

    ~SimpleClass() {
        std::cout << "SimpleClass Destructor" << std::endl;
    }
};

SimpleClass createObject() {
    SimpleClass obj;
    return obj;
}

void useObject(const SimpleClass& obj) {
    std::cout << "Using object inside useObject function" << std::endl;
}

int main() {
    SimpleClass newObj = createObject();
    useObject(newObj);

    return 0;
}
