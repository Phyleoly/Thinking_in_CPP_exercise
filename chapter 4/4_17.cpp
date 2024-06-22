#include <iostream>

int main()
{
    int *intPtr = new int;
    long *longPtr = new long;
    char *charPtr = new char[100];
    float *floatPtr = new float[100];

    std::cout << "intPtr " << intPtr << std::endl;
    std::cout << "longPtr " << longPtr << std::endl;
    std::cout << "charPtr " << (void *)charPtr << std::endl;
    std::cout << "floatPtr " << floatPtr << std::endl;

    delete intPtr;
    delete longPtr;
    delete[] charPtr;
    delete[] floatPtr;

    return 0;
}