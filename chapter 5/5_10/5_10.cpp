#include <iostream>
#include "Stash.h"

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
    Stash stash;
    stash.initialize(sizeof(Stash));

    for(int i = 0; i < 5; i++) {
        Hen hen;
        stash.add(&hen);
    }

    for(int i = 0; i < 5; i++) {
        Hen *henPtr;
        henPtr = static_cast<Hen *>(stash.fetch(i));
        henPtr->display();
    }

    return 0;
}