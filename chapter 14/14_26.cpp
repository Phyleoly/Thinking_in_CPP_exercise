#include <iostream>
#include <vector>

class Rock {
public:
    Rock() {
        std::cout << "Default constructor called" << std::endl;
    }

    Rock(const Rock& other) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Rock& operator=(const Rock& other) {
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    ~Rock() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    std::vector<Rock> rocks;
    rocks.push_back(Rock()); 
    rocks.push_back(Rock()); 
    rocks.push_back(Rock()); 

    
    std::cout << "Vector elements:" << std::endl;
    for (const auto& rock : rocks) {
    }

    std::vector<Rock*> rockPointers;
    rockPointers.push_back(new Rock()); 
    rockPointers.push_back(new Rock()); 
    rockPointers.push_back(new Rock()); 

    std::cout << "Vector elements:" << std::endl;
    for (auto ptr : rockPointers) {
        delete ptr; 
    }
    rockPointers.clear();

    // Using vector<Rock&> (references are not allowed in vectors)
    // std::vector<Rock&> rockReferences; // This is not allowed
    // Vector cannot store references because references must be initialized at creation and cannot be reassigned.

    return 0;
}