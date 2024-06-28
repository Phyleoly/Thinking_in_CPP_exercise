#include <iostream>

int main() {
    double arr[] = {1.0, 1.2, 1.3, 1.4, 1.5};

    double * const ptr = arr;
    ptr[1] = 1.1;
    for(int i = 0; i < 5; ++i)
        std::cout << ptr[i] << " ";
    // ptr++;

    return 0;
}