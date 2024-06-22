#include "CppLib.h"
#include <iostream>

int main()
{
    Stash stash;
    stash.initialize(25);

    for(int i = 0; i < 25; i++) { 
        double tmp = i + 1.1;
        stash.add(&tmp);
    }

    for(int i = 0; i < 25; i++) {
        double *tmp = (double *)stash.fetch(i);
        std::cout << *tmp << " ";
    }

    std::cout << std::endl;
    stash.cleanup();

    return 0;
}