#include <iostream>

void printArray(const int arr[], int size);

int main() 
{
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Array 1: ";
    printArray(arr1, size1);

    int arr2[] = {6, 7, 8};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Array 2: ";
    printArray(arr2, size2);

    char ch = 'A';

    std::cout << "Array 2 after defining char variable: ";
    printArray(arr2, size2);

    return 0;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}