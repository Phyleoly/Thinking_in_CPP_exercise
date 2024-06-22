#ifndef _STACK_OF_INT_H
#define _STACK_OF_INT_H

class StackOfInt {
private:
    struct Impl;
    Impl* impl;
public:
    StackOfInt();
    ~StackOfInt();
    int pop();
    void push(int x);
    int peek();
};

#endif