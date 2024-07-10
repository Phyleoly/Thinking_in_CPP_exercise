#include <iostream>

class Counted {
private:
    int id;
    static int count;
public:
    Counted() : id(count) {
        count++;
        std::cout << "id = " << id << std::endl
                  << "it's being created" << std::endl;
    }

    ~Counted() {
        std::cout << "id = " << id << std::endl
                  << "it's being destroyed" << std::endl;
    }
};

int Counted::count = 0;

int main() {
    Counted counted1;

    Counted* counted2 = new Counted;
    delete counted2;

    return 0;
}