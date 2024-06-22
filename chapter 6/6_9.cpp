#include <iostream>

class Simple {
private:
    int m_para;

public:
    Simple(int para) : m_para(para) {
        std::cout << "An object of class Simple has been created with parameter: " << m_para << std::endl;
    }

    ~Simple() {
        std::cout << "An object of class Simple has been destroyed with parameter: " << m_para << std::endl;
    }

    void printInfo() const {
        std::cout << "Printing info for object with parameter: " << m_para << std::endl;
    }
};

int main() {
    const int arraySize = 3;
    Simple* simpleArray[arraySize] = { new Simple(1), new Simple(2), new Simple(3) };

    std::cout << "Size of array: " << arraySize << std::endl;

    for (int i = 0; i < arraySize; ++i) {
        simpleArray[i]->printInfo();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete simpleArray[i];
    }

    return 0;
}