#include <iostream>

class Fi {
public:
    Fi() {
        std::cout << "Fi() constructor" << std::endl;
    }
};

class Fee {
public:
    Fee(int) {
        std::cout << "Fee() constructor" << std::endl;
    }
    Fee(const Fi&) {
        std::cout << "Fee() copy constructor" << std::endl; 
    }
};

int main() {
    Fee fee = 1;
    Fi fi;
    Fee fum = fi;
    
    return 0;
}