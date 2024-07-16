#include <cstring> 
#include <iostream>

template<class T>
class PStash {
    int quantity; 
    int next; 
    T** storage;
    int incr; 

    void inflate() {
        const int psz = sizeof(T*);
        int newIncr = incr * 2; 
        T** st = new T*[quantity + newIncr];
        memset(st, 0, (quantity + newIncr) * psz);
        memcpy(st, storage, quantity * psz);
        quantity += newIncr;
        delete []storage; 
        storage = st; 
        incr = newIncr; 
        std::cout << "inflate() called. New increment value: " << incr << std::endl;
    }

public:
    PStash(int initialIncr = 10) : quantity(0), next(0), storage(nullptr), incr(initialIncr) {}

    ~PStash() {
        for(int i = 0; i < next; i++) {
            delete storage[i]; 
            storage[i] = nullptr; 
        }
        delete []storage;
    }

    int add(T* element) {
        if(next >= quantity)
            inflate();
        storage[next++] = element;
        return(next - 1); 
    }

    T* operator[](int index) const {
        require(index >= 0,
            "PStash::operator[] index negative");
        if(index >= next)
            return nullptr; 
        require(storage[index] != nullptr,
            "PStash::operator[] returned null pointer");
        return storage[index];
    }

    T* remove(int index) {
        T* v = operator[](index);
        if(v != nullptr) storage[index] = nullptr;
        return v;
    }

    int count() const { return next; }
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

    for (int i = 0; i < 20; ++i) {
        stash.add(new Test(i));
    }

    std::cout << "Elements in stash:" << std::endl;
    for (int i = 0; i < stash.count(); ++i) {
        std::cout << stash[i]->getValue() << " ";
    }
    std::cout << std::endl;

    for (int i = 20; i < 40; ++i) {
        stash.add(new Test(i));
    }

    std::cout << "Elements in stash after second inflate:" << std::endl;
    for (int i = 0; i < stash.count(); ++i) {
        std::cout << stash[i]->getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}