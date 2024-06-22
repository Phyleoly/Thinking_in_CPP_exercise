#include "StackOfInt.h"
#include <vector>

struct StackOfInt::Impl {
    std::vector<int> stack;
    int top;
};

StackOfInt::StackOfInt() {
    impl->top = 0;
}

StackOfInt::~StackOfInt() {
    delete impl;    
}

int StackOfInt::pop() {
    impl->top--;
    return impl->stack[impl->top];
}

void StackOfInt::push(int x) {
    impl->stack[impl->top] = x;
    impl->top++;
}

int StackOfInt::peek() {
    return impl->stack[impl->top - 1];
}