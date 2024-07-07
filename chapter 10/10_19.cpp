#include <iostream>

namespace Me {
    class Us {
        friend void you(); 
    };
}

void you() {
    std::cout << "you() called" << std::endl;
}

int main() {
    you();

    return 0;
}
