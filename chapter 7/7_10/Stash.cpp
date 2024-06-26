#include "Stash.h"
#include <iostream>
#include <cassert>

const int increment = 100;

void Stash::initialize(int sz) {
    size = sz;
    quantity = 0;
    next = 0;
    mem = Mem(); // Initialize Mem instance
}

int Stash::add(const void *element) {
    if(next >= quantity)
        inflate(increment);
    int startBytes = next * size;
    unsigned char *e = (unsigned char *)element;
    unsigned char *p = mem.pointer(startBytes); // Use Mem to get pointer
    for(int i = 0; i < size; i++)
        p[i] = e[i];
    next++;
    return (next - 1);
}

void *Stash::fetch(int index) {
    assert(0 <= index);
    if (index >= next)
        return 0;
    return mem.pointer(index * size); // Use Mem to fetch pointer
}

int Stash::count() {
    return next;
}

void Stash::inflate(int increase) {
    assert(increase > 0);
    int newQuantity = quantity + increase;
    mem.ensureMinSize(newQuantity * size); // Use Mem to ensure minimum size
    quantity = newQuantity;
}

void Stash::cleanup() {
    std::cout << "freeing storage" << std::endl;
    // Mem's destructor handles deleting storage
}