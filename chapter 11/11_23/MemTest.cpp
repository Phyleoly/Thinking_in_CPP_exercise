#include "Mem.h"
#include <cstring>
#include <iostream>

class MyString {
    Mem* buf;
public:
    MyString();
    MyString(char* str);
    ~MyString();
    void concat(char* str);
    void print(std::ostream& os);
};

MyString::MyString() { buf = nullptr; }

MyString::MyString(char* str) {
    buf = new Mem(strlen(str) + 1);
    strcpy((char*)buf->pointer(), str);
}

void MyString::concat(char* str) {
    if(!buf) buf = new Mem;
    strcat((char*)buf->pointer(
        buf->msize() + strlen(str) + 1), str);
}

void MyString::print(std::ostream& os) {
    if(!buf) return;
    os << buf->pointer() << std::endl;
}

MyString::~MyString() { delete buf; }

int main() {
    MyString s("My test string");
    s.print(std::cout);
    s.concat(" some additional stuff");

    MyString s2;
    s2.concat("Using default constructor");
    s2.print(std::cout);

    return 0;
}