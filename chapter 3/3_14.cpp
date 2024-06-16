#include <iostream>

int main()
{
    int i;
    std::cout << "type a number and 'Enter'" << std::endl;
    std::cin >> i;
    std::cout << (i >= 5 ? (i > 5 ? "It's greater than 5" : "It's equal to 5") : "It's less thar 5");
}