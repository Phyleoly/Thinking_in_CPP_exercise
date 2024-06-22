#include <iostream>
#include "Stack.h"

class Hen {
public:
    class Nest {
    public:
        class Egg {
        public:
            void display() {
                std::cout << "This is an Egg." << std::endl;
            }
        };

        void display() {
            std::cout << "This is a Nest." << std::endl;
        }
    };

    void display() {
        std::cout << "This is a Hen." << std::endl;
    }
};

int main() {
    Stack stack;
    stack.initialize();

    for(int i = 0; i < 5; i++) {
        Hen hen;
        stack.push(&hen);
    }

    for(int i = 0; i < 5; i++) {
        Hen *henPtr;
        henPtr = static_cast<Hen *>(stack.pop());
        henPtr->display();
    }

    return 0;
}