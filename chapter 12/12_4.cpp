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

    MyClass& operator++() {
        data++;
        return *this;
    }
    
    MyClass& operator++(int) {
        MyClass tmp(*this);
        data++;
        return tmp;
    }
 
    MyClass& operator--() {
        data--;
        return *this;
    }
    
    MyClass& operator--(int) {
        MyClass tmp(*this);
        data--;
        return tmp;
    }
    
    
    void print(std::ostream& os) {
        os << data << std::endl;
    }
};

int main() {
    MyClass a(1);
    a++;
    a.print(std::cout);
    ++a;
    a.print(std::cout);
    a--;
    a.print(std::cout);
    --a;
    a.print(std::cout);

    return 0;
}