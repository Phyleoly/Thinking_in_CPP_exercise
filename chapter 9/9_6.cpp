#include <iostream>

inline void inlineFunction() {
    std::cout << "This is an inline function." << std::endl;
}

int main() {
    inlineFunction();

    return 0;
}