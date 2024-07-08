#include <iostream>

class Dog {
public:
    void bark() {
        std::cout << "Dog is barking!" << std::endl;
    }

    void fetch() {
        std::cout << "Dog is fetching!" << std::endl;
    }
};

class DogPointer {
    Dog* ptr;

public:
    explicit DogPointer(Dog* p = nullptr) : ptr(p) {}

    Dog* operator->() const {
        return ptr;
    }

    struct Callable {
        void operator()(Dog* obj, void (Dog::* func)()) const {
            (obj->*func)();
        }
    };

    Callable operator->*(void (Dog::* func)()) const {
        return Callable{};
    }
};

int main() {
    Dog dog;

    DogPointer ptr(&dog);
    
    ptr->*(&Dog::bark);

    ptr->*(&Dog::fetch);

    return 0;
}
