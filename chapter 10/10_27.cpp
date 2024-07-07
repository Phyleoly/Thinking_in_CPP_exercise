#include <iostream>

class MyClass {
private:
    int val;
public:
    MyClass(int para) : val(para) {}
    void print() {
        std::cout << val << std::endl;
    }
};

class MyClass2 {
private:
    static MyClass myClass;
public:
    static void print() {
        myClass.print();
    }
};

MyClass MyClass2::myClass = MyClass(5);

int main() {
    MyClass2::print();

    return 0;
}