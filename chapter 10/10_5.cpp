#include <iostream>

class Monitor {
public:
    void incident() {
        std::cout << "in function incident" << std::endl;
        _how_many++;
    }

    void decrement() {
        std::cout << "in function decrement" << std::endl;
        _how_many--;
    }

    void print() {
        std::cout << "function incident has been used " << _how_many << " times" << std::endl;
    }

private:
    static int _how_many;
};

int Monitor::_how_many = 0;

class Monitor2 {
public:
    Monitor2(Monitor* val) : ptr(val) {
        ptr->incident();
        ptr->print();
    }

    ~Monitor2() {
        ptr->decrement();
        ptr->print();
    }

private:
    Monitor* ptr;
};

void f() {
    static Monitor monitor;
    static Monitor2 monitor2(&monitor);
}

int main() {
    f();
    f();
    f();
    std::cout << std::endl;
    Monitor monitor;
    Monitor2 test(&monitor);

    std::cout << std::endl;

    return 0;
}