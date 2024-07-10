#include <iostream>
#include <vector>

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

    void f() {
        std::cout << "id = " << id
                  << " f() called" << std::endl; 
    }
};

int Counted::count = 0;

int main() {
    std::vector<Counted*> vec;
    for(int i = 0; i < 5; i++)
        vec.push_back(new Counted);

    for(int i = 0; i < 5; i++)
        vec[i]->f();

    for(int i = 0; i < 5; i++)
        delete vec[i];
    

    return 0;
}