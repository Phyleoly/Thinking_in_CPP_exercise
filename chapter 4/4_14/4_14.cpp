#include <iostream>
#include <string>
#include "Stack.h"

class Video {
private:
    int m_id;
    float m_rents; 
    std::string m_title;
    bool m_isRented;

public:
    Video(int id, float rents, std::string title);
    ~Video();
    void print();
};

Video::Video(int id, float rents, std::string title)
    : m_id(id), m_rents(rents), m_title(title), m_isRented(false) {}

Video::~Video() {}

void Video::print() {
    std::cout << "ID: " << m_id << ", Rents: " << m_rents
              << ", Title: " << m_title << std::endl;
    if (m_isRented)
        std::cout << "Status: Rented" << std::endl;
    else
        std::cout << "Status: Available" << std::endl;
}

int main() 
{
    Stack stack;
    stack.initialize();

    for(int i = 0; i < 5; i++) {
        Video tmp(i, i + 3.5, i + "abc");
        stack.push(&tmp);
    }

    for(int i = 0; i < 5; i++) {
        Video* tmp;
        tmp = (Video *)stack.pop();
        tmp->print();
    }

    return 0;
}