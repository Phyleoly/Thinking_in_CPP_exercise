#ifndef _STACK_H
#define _STACK_H

template <class T>
class Stack {
private:
    struct Link {
        T* data;
        Link* next;
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
    } *head;

public:
    Stack() : head(nullptr) {}
    ~Stack();

    void push(T* dat) {
        head = new Link(dat, head); 
    }

    T* peek() const {
        return head ? head->data : nullptr;
    }

    T* pop();

    class iterator;
    friend class iterator;
    class iterator {
    private:
        Link* ptr;
    public:
        iterator(const Stack<T>& stack) : ptr(stack.head) {}
        iterator(const iterator& other) : ptr(other.ptr) {}
        iterator() : ptr(nullptr) {}

        iterator& operator++() { 
            if (ptr)
                ptr = ptr->next;
            return *this;
        }

        iterator operator++(int) { 
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator!=(const iterator& other) const {
            return ptr != other.ptr;
        }

        T* operator*() const {
            return ptr ? ptr->data : nullptr;
        }
    };

    iterator begin() const {
        return iterator(*this);
    }

    iterator end() const {
        return iterator();
    }
};

template<class T>
T* Stack<T>::pop() {
    if (head == nullptr)
        return nullptr;
    T* ret = head->data;
    Link* tmp = head;
    head = head->next;
    delete tmp;
    return ret;
}

template<class T>
Stack<T>::~Stack() {
    while (head) {
        Link* tmp = head;
        head = head->next;
        delete tmp->data; 
        delete tmp;
    }
}

#endif // _STACK_H