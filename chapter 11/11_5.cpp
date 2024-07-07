#include <iostream>

class TestClass {
public:
    TestClass(int value) : data(value) {}

    void setValue(int value) {
        data = value;
    }

    int getValue() const {
        // data = 10;
        return data;
    }

    void printValue() const {
        std::cout << "Value: " << data << std::endl;
    }

private:
    int data;
};

void testConstMemberFunctions(const TestClass& obj) {
    int value = obj.getValue();
    std::cout << "Inside testConstMemberFunctions - Value: " << value << std::endl;
    
    // obj.setValue(20);
    
    obj.printValue(); 
}

int main() {
    TestClass obj(42);
    
    std::cout << "Initial value: " << obj.getValue() << std::endl;
    
    obj.setValue(100);
    std::cout << "After setValue: " << obj.getValue() << std::endl;
    
    testConstMemberFunctions(obj);

    return 0;
}
