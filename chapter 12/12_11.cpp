#include <iostream>

class Number {
private:
    double data;
public:
    Number(double dat) : data(dat) {}

    Number operator+(const Number& obj) {
        return Number(data + obj.data);
    }

    Number operator-(const Number& obj) {
        return Number(data - obj.data);
    }

    Number operator*(const Number& obj) {
        return Number(data * obj.data);
    }

    Number operator/(const Number& obj) {
        return Number(data / obj.data);
    }

    operator double() const {
        return data;
    }

    double getData() const { return data; }
};

int main() {
    Number a(1.1), b(1.4);
    Number c = a + b * a / b;

    std::cout << c.getData() << std::endl;
}