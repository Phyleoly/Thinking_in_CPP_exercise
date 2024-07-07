#include <iostream>

class IntArray {
private:
    static const int arraySize = 5;  
    const int constVar;              

    int arr[arraySize];              
    static int staticVar;            

public:
    inline IntArray(int constValue) : constVar(constValue) {
        for (int i = 0; i < arraySize; ++i) {
            arr[i] = i + 1;  
        }
    }

    inline void print() const {
        std::cout << "Array elements:";
        for (int i = 0; i < arraySize; ++i) {
            std::cout << " " << arr[i];
        }
        std::cout << std::endl;
        printStaticVar();
    }

    static void printStaticVar() {
        std::cout << "Static variable staticVar: " << staticVar << std::endl;
    }
};

int IntArray::staticVar = 100;

int main() {
    IntArray arrayInstance(42);

    arrayInstance.print();

    return 0;
}