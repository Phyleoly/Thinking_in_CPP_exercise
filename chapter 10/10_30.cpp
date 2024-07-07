#include <iostream>

void demonstrateStructArray() {
    struct MyStruct {
        int number;  
        MyStruct() : number(0) {}  
    };

    const int arraySize = 5;
    MyStruct objects[arraySize];  

    std::cout << "Array of MyStruct objects:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Object " << i << ": number = " << objects[i].number << std::endl;
    }
}

int main() {
    demonstrateStructArray();
    return 0;
}
