#ifndef VALUESTACK_H
#define VALUESTACK_H

#include <vector>
#include <stdexcept>

template<class T>
class Stack {
private:
    std::vector<T> stack;

public:
    Stack() = default;

    void push(const T& x) {
        stack.push_back(x);
    }

    T peek() const {
        if (!stack.empty()) {
            return stack.back();
        } else {
            throw std::out_of_range("ValueStack<>::peek(): empty stack");
        }
    }

    T pop() {
        if (!stack.empty()) {
            T topElement = stack.back();
            stack.pop_back();
            return topElement;
        } else {
            throw std::out_of_range("ValueStack<>::pop(): empty stack");
        }
    }

    bool empty() const {
        return stack.empty();
    }

    size_t size() const {
        return stack.size();
    }

    void clear() {
        stack.clear();
    }
};

#endif // VALUESTACK_H