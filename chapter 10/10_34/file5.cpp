#include "Mirror.h"
#include <iostream>

extern Mirror& mirror4();
Mirror mirror5(&mirror4());

int main() {
    std::cout << mirror5._test() << std::endl;
}