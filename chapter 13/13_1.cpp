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
    Counted counted1, counted2, counted3;

    return 0;
}