#include <iostream>

void f(char& para) {
    para = 'b';
}

int main() {
    char a = 'a';
    std::cout << a << std::endl;

    f(a);
    std::cout << a << std::endl;
}