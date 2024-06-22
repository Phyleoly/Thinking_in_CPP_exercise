#include "Stash.h"
#include <iostream>

int main() {
    Stash stash;

    stash.initialize(sizeof(double));

    double d = 1.1;
    stash.add(&d);

    double *dp = static_cast<double*>(stash.fetch(0));
    std::cout << "Fetched double: " << *dp << std::endl;

    stash.cleanup();

    return 0;
}