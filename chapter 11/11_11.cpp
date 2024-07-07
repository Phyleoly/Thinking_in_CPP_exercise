#include <iostream>

void testFunction(char c, int i, float f, double d) {
    std::cout << c << " " << i << " " << f << " " << d << std::endl;
}

int main() {
    char c = 'A';
    int i = 10;
    float f = 3.14f;
    double d = 2.71828;

    testFunction(c, i, f, d);

    return 0;
}