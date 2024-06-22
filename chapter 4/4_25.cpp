#include <iostream>

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head;
    void generateLinkedList(int length);
    void print();
    void cleanup();
};


void LinkedList::generateLinkedList(int length) {
    if (length <= 0) {
        head = nullptr;
    }

    head = new Node{0, nullptr};  
    Node* current = head;

    for (int i = 1; i < length; ++i) {
        current->next = new Node{i, nullptr};  
        current = current->next;
    }
}

void LinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Node at " << current << ", data = " << current->data << std::endl;
        current = current->next;
    }
}

void LinkedList::cleanup() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    int length = 5;  
    LinkedList ll;
    ll.generateLinkedList(length);
    ll.print();
    ll.cleanup();
    
    return 0;
}