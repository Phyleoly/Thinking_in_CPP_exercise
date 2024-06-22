#include "Stack.h"
#include <iostream>

int main()
{
    Stack stack;
    stack.initialize();

    for(int i = 0; i < 25; i++) { 
        double tmp = i + 1.1;
        stack.push(&tmp);
    }

    for(int i = 0; i < 25; i++) {
        double *tmp = (double *)stack.pop();
        std::cout << *tmp << " ";
    }

    std::cout << std::endl;
    stack.cleanup();

    return 0;
}