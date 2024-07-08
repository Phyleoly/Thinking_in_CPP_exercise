#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    Counter& operator++() {
        ++count;
        return *this;
    }

    Counter operator++(int) {
        Counter temp(*this); 
        ++(*this);           
        return temp;         
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter c;

    std::cout << "Prefix increment:" << std::endl;
    std::cout << "Before: " << c.getCount() << std::endl;
    ++c; 
    std::cout << "After prefix increment: " << c.getCount() << std::endl;

    std::cout << std::endl;

    std::cout << "Postfix increment:" << std::endl;
    std::cout << "Before: " << c.getCount() << std::endl;
    c++; 
    std::cout << "After postfix increment: " << c.getCount() << std::endl;

    return 0;
}
