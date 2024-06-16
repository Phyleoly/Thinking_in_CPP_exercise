#include <iostream>

void printArr(double* arr, size_t size) {
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
    return;
}

int main()
{
    double arr[5] = {0, 0, 0, 0, 0};
    printArr(arr, 5);

    unsigned char * ptr;
    ptr = reinterpret_cast<unsigned char *>(arr);
    for(int i = 0; i < 5 * sizeof(double); i++)
        ptr[i] = 1;

    printArr(arr, 5);
    
    return 0;
}