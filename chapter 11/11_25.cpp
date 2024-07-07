#include <iostream>

class IntArray {
public:
    IntArray(size_t size) : size(size) {
        arr = new int[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = 0;  
        }
    }

    ~IntArray() {
        delete[] arr;
    }

    void set(size_t index, int value) {
        if (index < size) {
            arr[index] = value;
        }
    }

    int get(size_t index) const {
        if (index < size) {
            return arr[index];
        }
        return -1;  
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int* arr;

private:
    size_t size;
};

int main() {
    IntArray myArray(5);  

    for (size_t i = 0; i < 5; ++i) {
        myArray.set(i, static_cast<int>(i * 10));
    }

    myArray.print();  

    int* IntArray::*ptr = &IntArray::arr;  

    for (size_t i = 0; i < 5; ++i) {
        std::cout << (myArray.*ptr)[i] << " ";  
    }
    std::cout << std::endl;

    return 0;
}