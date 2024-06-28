#include <iostream>
#include <string>

class MyString {
public:
    MyString(std::string string) : m_string(string) {}
    void print() { std::cout<< m_string; }
private:
    std::string m_string;
};

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

Stack::Stack(void* arr[], size_t size) {
    head = nullptr;
    for(int i = 0; i < size; i++) {
        push(arr[i]);
    }
}

void Stack::push(void* data) {
    head = new Link(data, head);
}

void* Stack::peek() {
    if(head == nullptr) return nullptr;
    return head->data;
}

void* Stack::pop() {
    if(head == nullptr) return nullptr;
    void* result = head->data;
    Link* oldLink = head;
    head = head->next;
    delete oldLink;
    return result;
}

int main() {
    Stack stringStack;
    for(int i = 0; i < 5; ++i) {
        MyString newMyString("abc");
        stringStack.push(&newMyString);
    }

    for(int i = 0; i < 5; ++i) {
        MyString* myString = (MyString*)stringStack.pop();
        myString->print();
        std::cout << std::endl;
    }

    return 0;
}