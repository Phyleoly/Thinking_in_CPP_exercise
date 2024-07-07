#include <iostream>

void modifyPointerValue(int* ptr, int& result) {
    if (ptr != nullptr) {
        *ptr = *ptr * 2;  
        result = *ptr;    
    } else {
        throw std::invalid_argument("nullptr passed to modifyPointerValue function");
    }
}

int main() {
    int value = 10;
    int* ptr = &value;

    std::cout << "Before modification: value = " << value << std::endl;

    int modifiedValue;
    try {
        modifyPointerValue(ptr, modifiedValue);
        std::cout << "After modification: value = " << value << ", modifiedValue = " << modifiedValue << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    int* nullPtr = nullptr;
    try {
        modifyPointerValue(nullPtr, modifiedValue); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
