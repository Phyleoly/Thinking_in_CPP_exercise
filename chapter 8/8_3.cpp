#include <iostream>

int main() {
    const int i = 5;
    const int j = 10;

    const double pi = 3.14159;
    const float e = 2.71828f;

    const char ch = 'A';

    int sum = i + j;
    double circleArea = pi * 2.0 * 2.0;
    float exponential = e * e;

    std::cout << "Sum of i and j: " << sum << std::endl;
    std::cout << "Area of circle with radius 2: " << circleArea << std::endl;
    std::cout << "Exponential of e: " << exponential << std::endl;

    return 0;
}
