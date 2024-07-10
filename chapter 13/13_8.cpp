#include <iostream>

class Counted {
private:
    int id;
    static int count;

public:
    Counted() : id(count) {
        count++;
        std::cout << "id = " << id 
                  << " it's being created" << std::endl;
    }

    ~Counted() {
        std::cout << "id = " << id 
                  << " it's being destroyed" << std::endl;
    }
};

int Counted::count = 0;

int main() {
    Counted* counteds[5];
    for(int i = 0; i < 5; i++)
        counteds[i] = new Counted;

    delete counteds;

    return 0;
}