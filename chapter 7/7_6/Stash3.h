#ifndef _STASH3_H
#define _STASH3_H

class Stash {
    int size;
    int quantity;
    int next;

    unsigned char *storage;
    void inflate(int increase);
public:
    Stash(int sz, int quantity = 0, int next = 0);
    ~Stash();
    int add(void* element);
    void* fetch(int index);
    int count();
};

#endif