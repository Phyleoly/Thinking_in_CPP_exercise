#include <iostream>

class Hen {
public:
    class Nest {
    private:
        int nestData;

    public:
        Nest(int data) : nestData(data) {}

        class Egg {
        private:
            int eggData;

        public:
            Egg(int data) : eggData(data) {}

            friend class Nest; // Nest is a friend of Egg to access private data

            void display() {
                std::cout << "Egg Data: " << eggData << std::endl;
            }
        };

        friend class Hen; // Hen is a friend of Nest to access private data

        void display() {
            std::cout << "Nest Data: " << nestData << std::endl;
        }
    };

    void display() {
        std::cout << "This is a Hen." << std::endl;
    }
};

int main() {
    Hen hen;
    Hen::Nest nest(10); // Create Nest with data 10
    Hen::Nest::Egg egg(20); // Create Egg with data 20

    hen.display();    // Display Hen
    nest.display();   // Display Nest with data 10
    egg.display();    // Display Egg with data 20

    return 0;
}