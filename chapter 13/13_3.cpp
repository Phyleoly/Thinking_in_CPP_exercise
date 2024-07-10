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

class PStash {
private:
    Counted* counted;
public:
    PStash() : counted(new Counted) {
        std::cout << "PStash created" << std::endl;
    }

    ~PStash() {
        std::cout << "PStash destroyed" << std::endl;
        delete counted;
    }
};

int main() {
    PStash p1, p2;

    return 0;
}