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
    const int size = 5;
    Counted* arr = new Counted[size];

    for (int i = 0; i < size; ++i) {
        delete &arr[i]; 
    }

    delete[] arr; 

    return 0;
}