#include <iostream>

class B;

class A {
    int value;

public:
    A(int v) : value(v) {}

    A operator+(const B& b) const;

    static A convertFromB(const B& b);

    int getValue() const {
        return value;
    }

    friend std::ostream& operator<<(std::ostream& os, const A& a);
};

class B {
    int value;

public:
    B(int v) : value(v) {}

    B operator+(const A& a) const;

    static B convertFromA(const A& a) {
        return B(a.getValue());
    }

    int getValue() const {
        return value;
    }

    friend std::ostream& operator<<(std::ostream& os, const B& b);
};

A A::convertFromB(const B& b) {
    return A(b.getValue());
}

A A::operator+(const B& b) const {
    return A(value + b.getValue());
}

B B::operator+(const A& a) const {
    return B(value + a.getValue());
}

std::ostream& operator<<(std::ostream& os, const A& a) {
    os << "A(" << a.value << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const B& b) {
    os << "B(" << b.value << ")";
    return os;
}

int main() {
    A a(5);
    B b(10);

    A result1 = a + b;
    B result2 = b + a;

    std::cout << "a + b = " << result1 << std::endl;
    std::cout << "b + a = " << result2 << std::endl;

    A result3 = a + B::convertFromA(a);
    B result4 = b + A::convertFromB(b);

    std::cout << "a + B::convertFromA(a) = " << result3 << std::endl;
    std::cout << "b + A::convertFromB(b) = " << result4 << std::endl;

    return 0;
}
