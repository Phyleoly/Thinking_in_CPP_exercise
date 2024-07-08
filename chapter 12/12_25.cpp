#include <iostream>

class After {
public:
    const After& operator,(const After&) const {
        std::cout << "After::operator,()" << std::endl;
        return *this;
    }
};

class Before {};

Before& operator,(int, Before& b) {
    std::cout << "Before::operator,()" << std::endl;
    return b;
}

int main() {
    After a, b;
    a, b;

    Before c;
    // 1, c;
}