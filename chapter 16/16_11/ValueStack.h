#ifndef VALUESTACK_H
#define VALUESTACK_H

#include <vector>
#include <stdexcept>

template<class T>
class Stack {
private:
    std::vector<T> stack;
    int top;

public:
    Stack() : top(0) {}

    void push(const T& x) {
        if (top >= stack.size()) {
            stack.push_back(x);
        } else {
            stack[top] = x;
        }
        ++top;
    }

    T peek() const {
        if (top > 0) {
            return stack[top - 1];
        } else {
            throw std::out_of_range("Stack<>::peek(): empty stack");
        }
    }

    T pop() {
        if (top > 0) {
            return stack[--top];
        } else {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
    }

    bool empty() const {
        return top == 0;
    }

    size_t size() const {
        return top;
    }

    void clear() {
        stack.clear();
        top = 0;
    }
};

#endif // VALUESTACK_H