#include <iostream>
#include <cstring>

class MyClass {
public:
    MyClass(int size) {
        memset(arr, 0, size);
    }
    void print() {
        for(int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
    }
private:
    int* arr;
    int size;
};

int main() {
    MyClass myClass(5);

    myClass.print();

    return 0;
}