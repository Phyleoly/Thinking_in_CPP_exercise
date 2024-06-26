#include "Stash3.h"
#include <iostream>
#include <cassert>

const int increment = 100;

Stash::Stash(int sz, int quantity, int next) : size(sz), quantity(quantity), next(next), storage(nullptr) {
    if(quantity != 0)
        inflate(quantity);
}

Stash::~Stash() {
    if(storage != 0) {
        std::cout << "freeing storage" << std::endl;
        delete []storage;
    }
}

int Stash::add(void* element) {
    if(next >= quantity)
        inflate(increment);
    int startBytes = next * size;
    unsigned char* e = (unsigned char*)element;
    for(int i = 0; i < size; i++)
        storage[startBytes + i] = e[i];
    next++;
    return (next - 1);
}

void* Stash::fetch(int index) {
    if(index < 0)
        std::cerr << "Stash::fetch (-)need index >= 0";
    if(index >= next)
        return 0;
    return &(storage[index * size]);
}

int Stash::count() {
    return next;
}

void Stash::inflate(int increase) {
    assert(increase >= 0);
    if(increase == 0) return;
    int newQuantity = quantity + increase;
    int newBytes = newQuantity * size;
    int oldBytes = quantity * size;
    unsigned char* b = new unsigned char[newBytes];
    for(int i = 0; i < oldBytes; i++)
        b[i] = storage[i];
    delete [](storage);
    storage = b;
    quantity = newQuantity;
}