#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    Counter& operator++() {
        ++count;
        std::cout << "Prefix increment called" << std::endl;
        return *this;
    }

    Counter& operator--() {
        --count;
        std::cout << "Prefix decrement called" << std::endl;
        return *this;
    }

    Counter operator++(int) {
        Counter temp(*this);
        ++(*this); 
        std::cout << "Postfix increment called" << std::endl;
        return temp;
    }

    Counter operator--(int) {
        Counter temp(*this);
        --(*this); 
        std::cout << "Postfix decrement called" << std::endl;
        return temp;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter c(5);

    ++c;
    --c;

    return 0;
}
