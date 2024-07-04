#include <iostream>

#define TRACE(s) do { std::cerr << #s << std::endl; s; } while(0)

int main() {
    int x = 10;
    TRACE(std::cout << "x = " << x << std::endl);
    TRACE(x++);
    TRACE(std::cout << "Updated x = " << x << std::endl);
    return 0;
}