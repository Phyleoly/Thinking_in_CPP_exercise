#include <iostream>

template<class T>
class PStash {
    int quantity; 
    int next; 
    T** storage;
    int incr; 

    void inflate(int increase) {
        const int psz = sizeof(T*);
        T** st = new T*[quantity + increase];
        memset(st, 0, (quantity + increase) * psz);
        memcpy(st, storage, quantity * psz);
        quantity += increase;
        delete []storage; 
        storage = st; 
    }

public:
    PStash(int incr = 10) : quantity(0), next(0), storage(0), incr(incr) {}

    ~PStash() {
        for(int i = 0; i < next; i++) {
            delete storage[i]; 
            storage[i] = 0; 
        }
        delete []storage;
    }

    int add(T* element) {
        if(next >= quantity)
            inflate(incr);
        storage[next++] = element;
        return(next - 1); 
    }

    T* operator[](int index) const {
        require(index >= 0,
            "PStash::operator[] index negative");
        if(index >= next)
            return 0; 
        require(storage[index] != 0,
            "PStash::operator[] returned null pointer");
        return storage[index];
    }

    T* remove(int index) {
        T* v = operator[](index);
        if(v != 0) storage[index] = 0;
        return v;
    }

    int count() const { return next; }

    void setIncr(int newIncr) {
        incr = newIncr;
    }
};

class Test {
public:
    Test(int v) : value(v) {}
    int getValue() const { return value; }
private:
    int value;
};

int main() {
    PStash<Test> stash(5);
    
    for (int i = 0; i < 10; ++i) {
        stash.add(new Test(i));
    }
    
    std::cout << "Initial elements:" << std::endl;
    for (int i = 0; i < stash.count(); ++i) {
        std::cout << stash[i]->getValue() << " ";
    }
    std::cout << std::endl;
    
    stash.setIncr(10);
    
    for (int i = 10; i < 25; ++i) {
        stash.add(new Test(i));
    }
    
    std::cout << "Elements after changing increment and adding more:" << std::endl;
    for (int i = 0; i < stash.count(); ++i) {
        std::cout << stash[i]->getValue() << " ";
    }
    std::cout << std::endl;

    std::cout << "Removing elements at index 5, 15, and 20:" << std::endl;
    delete stash.remove(5);
    delete stash.remove(15);
    delete stash.remove(20);

    std::cout << "Elements after removal:" << std::endl;
    for (int i = 0; i < stash.count(); ++i) {
        if (stash[i] != nullptr) {
            std::cout << stash[i]->getValue() << " ";
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;

    return 0;
}