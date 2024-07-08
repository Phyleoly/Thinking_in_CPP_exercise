#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;
public:
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    ~MyClass() {
        delete[] data;
    }

    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this; 

        delete[] data; 

        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        
        return *this;
    }

    void display() const {
        std::cout << data << std::endl;
    }
};

int main() {
    MyClass a("Hello");
    MyClass b("World");
    a = b; 

    a.display(); 
    b.display(); 

    return 0;
}
