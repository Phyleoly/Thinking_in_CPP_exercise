#ifndef _STACK_H
#define _STACK_H
#include <cstdio>

class Stack {
private:
    struct Link {
        void* data;
        Link* next;
        Link(void* data, Link* next) : data(data) , next(next) {}
        ~Link() {}
    }* head;
public:
    Stack() : head(nullptr) {}
    Stack(void* arr[], size_t size);
    ~Stack() {}
    void push(void* data);
    void* peek();
    void* pop();    
};

#endif