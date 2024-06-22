#include <iostream>

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
    Hen hen;
    Hen::Nest nest;
    Hen::Nest::Egg egg;

    hen.display();    // Display Hen
    nest.display();   // Display Nest
    egg.display();    // Display Egg

    return 0;
}