#include <iostream>

int f(double para) {
    return static_cast<int>(para);
}

int main()
{
    int (*fptr)(double);
    fptr = f;
    
    std::cout << (*fptr)(2.2) << std::endl;
    return 0;
}