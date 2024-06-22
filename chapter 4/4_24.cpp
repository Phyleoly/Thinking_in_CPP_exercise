#include <iostream>

// 定义结构体
struct Node {
    int data;      // 整型变量
    Node* next;    // 指向下一个结构体的指针
};

// 函数：生成链表
Node* generateLinkedList(Node* head, int length) {
    if (length <= 0) {
        return nullptr;
    }

    // 使用 new 生成新结构体，构建链表
    head = new Node{0, nullptr};  // 创建第一个结点，索引为0
    Node* current = head;

    for (int i = 1; i < length; ++i) {
        current->next = new Node{i, nullptr};  // 创建下一个结点，索引为i
        current = current->next;
    }

    return head;
}

// 函数：遍历并打印链表
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Node at " << current << ", data = " << current->data << std::endl;
        current = current->next;
    }
}

int main() {
    int length = 5;  // 要创建的链表长度
    Node* head = nullptr;

    // 生成链表
    head = generateLinkedList(head, length);

    // 打印链表
    printLinkedList(head);

    // 释放链表内存
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}