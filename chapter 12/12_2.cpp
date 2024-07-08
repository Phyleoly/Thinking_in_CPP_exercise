#include <ostream>
#include <iostream>

class MyClass {
private:
    int data;
public:
    MyClass(int dat) : data(dat) {}

    MyClass operator+(const MyClass& other) {
        data += other.data;
        return *this;
    }

    void print(std::ostream& os) {
        os << data << std::endl;
    }
};

int main() {
    MyClass a(1), b(2);
    a = a + b;

    a.print(std::cout);

    return 0;
}