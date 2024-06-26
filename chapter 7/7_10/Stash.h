#ifndef _STASH_H
#define _STASH_H

#include "Mem.h"

struct Stash {
    int size;
    int quantity;
    int next;
    Mem mem;

    void initialize(int size);
    void cleanup();
    int add(const void *element);
    void *fetch(int index);
    int count();
    void inflate(int increase);
};

#endif