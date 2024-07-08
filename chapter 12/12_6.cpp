#include <iostream>

class SimpleClass {
private:
    int value;

public:
    SimpleClass(int val) : value(val) {}

    SimpleClass operator+(const SimpleClass& other) const {
        return SimpleClass(value + other.value);
    }

    SimpleClass operator-(const SimpleClass& other) const {
        return SimpleClass(value - other.value);
    }

    SimpleClass& operator++() {
        ++value;
        return *this;
    }

    SimpleClass operator++(int) {
        SimpleClass temp(value);
        ++value;
        return temp;
    }

    SimpleClass& operator--() {
        --value;
        return *this;
    }

    SimpleClass operator--(int) {
        SimpleClass temp(value);
        --value;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const SimpleClass& obj) {
        os << obj.value;
        return os;
    }
};


int main() {
    SimpleClass a(5), b(3), c(2);

    SimpleClass result = a + b - c;
    std::cout << "a + b - c = " << result << std::endl;

    SimpleClass d(10);
    std::cout << "d = " << d << std::endl;
    std::cout << "++d = " << ++d << std::endl;
    std::cout << "d++ = " << d++ << std::endl;
    std::cout << "d after d++ = " << d << std::endl;

    SimpleClass e(8);
    std::cout << "e = " << e << std::endl;
    std::cout << "--e = " << --e << std::endl;
    std::cout << "e-- = " << e-- << std::endl;
    std::cout << "e after e-- = " << e << std::endl;

    return 0;
}