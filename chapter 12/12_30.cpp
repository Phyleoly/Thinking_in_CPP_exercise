#include <iostream>

class B;

class A {
    int value;

public:
    A(int v) : value(v) {}

    A operator+(const B& b) const;

    explicit operator A() const { return A(value); }

    friend std::ostream& operator<<(std::ostream& os, const A& a);
    int getValue() const { return value; }
};

class B {
    int value;

public:
    B(int v) : value(v) {}

    B operator+(const A& a) const;

    explicit operator B() const { return B(value); }

    friend std::ostream& operator<<(std::ostream& os, const B& b);
    int getValue() const { return value; }
};

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

    return 0;
}
