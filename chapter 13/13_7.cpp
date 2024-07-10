#include <iostream>
#include <vector>

class Counted {
private:
    int id;
    static int count;
public:
    Counted() : id(count) {
        count++;
        std::cout << "id = " << id 
                  << " it's being created" << std::endl;
    }

    ~Counted() {
        std::cout << "id = " << id 
                  << " it's being destroyed" << std::endl;
    }

    void f() {
        std::cout << "id = " << id
                  << " f() called" << std::endl; 
    }
};

int Counted::count = 0;

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
//     std::vector<Counted*> vec;
    Stack stack;
    for(int i = 0; i < 5; i++)
        // vec.push_back(new Counted);
        stack.push(new Counted);

    for(int i = 0; i < 5; i++) {
        // vec[i]->f();
        Counted* tmp = (Counted*)stack.pop();
        tmp->f();
        delete tmp;
    }

    for(int i = 0; i < 5; i++)
        // delete vec[i];
    

    return 0;
}