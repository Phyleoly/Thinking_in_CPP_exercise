#include <iostream>

void modifyPointer(int**& ptrPtr) {
    static int value = 42; 
    *ptrPtr = &value; 
}

int main() {
    int* ptr = nullptr; 
    int** val = &ptr;
    modifyPointer(val); 

    if (ptr != nullptr) {
        std::cout << "Value at ptr: " << *ptr << std::endl; // 输出静态值 42
    } else {
        std::cout << "ptr is nullptr" << std::endl;
    }

    return 0;
}
