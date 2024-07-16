#ifndef TSTACK2_H
#define TSTACK2_H

#include <vector>

template <typename T>
class TStack2 {
public:
    TStack2();
    void push(const T& item);
    void pop();
    T top() const;
    bool isEmpty() const;

private:
    std::vector<T> data;
};

template <typename T>
TStack2<T>::TStack2() : data() {}

template <typename T>
void TStack2<T>::push(const T& item) {
    data.push_back(item);
}

template <typename T>
void TStack2<T>::pop() {
    if (!data.empty()) {
        data.pop_back();
    }
}

template <typename T>
T TStack2<T>::top() const {
    if (!data.empty()) {
        return data.back();
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T>
bool TStack2<T>::isEmpty() const {
    return data.empty();
}

#endif // TSTACK2_H