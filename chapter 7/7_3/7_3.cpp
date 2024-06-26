#include <iostream>

void foo(int x) {
    std::cout << "foo: " << x << std::endl;
}

int main() {
    foo(42);
    return 0;
}