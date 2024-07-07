#include <iostream>

class Monitor {
public:
    void incident() {
        std::cout << "in function incident" << std::endl;
        _how_many++;
    }

    void print() {
        std::cout << "function incident has been used " << _how_many << " times" << std::endl;
    }

private:
    static int _how_many;
};

int Monitor::_how_many = 0;

void f(int times) {
    Monitor monitor;
    for(int i = 0; i < times; i++)
        monitor.incident();
    monitor.print(); 
}

int main() {
    for(int i = 0; i < 10; i++)
        f(i);
    
    return 0;
}