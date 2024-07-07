#include <iostream>

class ArrayClass {
private:
    static const int constantArray[];
    static const int constantArraySize;

    static int nonConstantArray[];
    static const int nonConstantArraySize;

public:
    static void printConstantArray() {
        std::cout << "Constant Array Values:" << std::endl;
        for (int i = 0; i < constantArraySize; ++i) {
            std::cout << constantArray[i] << " ";
        }
        std::cout << std::endl;
    }

    static void printNonConstantArray() {
        std::cout << "Non-Constant Array Values:" << std::endl;
        for (int i = 0; i < nonConstantArraySize; ++i) {
            std::cout << nonConstantArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

const int ArrayClass::constantArray[] = {1, 2, 3, 4, 5};
const int ArrayClass::constantArraySize = sizeof(constantArray) / sizeof(constantArray[0]);

int ArrayClass::nonConstantArray[] = {10, 20, 30, 40, 50};
const int ArrayClass::nonConstantArraySize = sizeof(nonConstantArray) / sizeof(nonConstantArray[0]);

int main() {
    ArrayClass::printConstantArray();
    ArrayClass::printNonConstantArray();

    return 0;
}