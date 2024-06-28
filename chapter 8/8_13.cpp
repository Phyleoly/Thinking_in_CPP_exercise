#include <iostream>

void modifyConstParam(const int x) {
    // x = 20;
    std::cout << "Inside function: x = " << x << std::endl;
}

int main() {
    int num = 10;
    
    modifyConstParam(num);

    return 0;
}