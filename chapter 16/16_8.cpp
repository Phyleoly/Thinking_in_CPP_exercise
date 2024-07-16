#include <string>
#include <iostream>
#include <vector>

template <class T>
class Stack {
private:
    std::vector<T*> elements;
    bool own;
public:
    Stack(bool own = true) : own(own) {}
    ~Stack() {
        if(!own) return;
        delete[] elements;
    }

    void push(T* dat) {
        elements.push_back(dat);
    }

    T* peek() {
        return elements.back();
    }

    T* pop() {
        T* tmp = peek();
        elements.pop_back();
        return tmp;
    }

    bool owns const { return own; }
    void owns(bool newownership) { own = newownership; }
};

int main() {}