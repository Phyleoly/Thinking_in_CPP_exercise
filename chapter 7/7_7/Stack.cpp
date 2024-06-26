#include "Stack.h"

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


