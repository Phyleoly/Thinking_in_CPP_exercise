#include "Mem.h"
#include <iostream>
#include <cstring>

Mem::Mem() { mem = 0; size = 0; }

Mem::Mem(int sz) {
    mem = 0;
    size = 0;
    ensureMinSize(sz);
}

Mem::~Mem() { delete[] mem; }

int Mem::msize() { return size; }

void Mem::ensureMinSize(int minSize) {
    if(size < minSize) {
        byte* newmem = new byte[minSize];

        memset(newmem + size, 0, minSize - size);
        memcpy(newmem, mem, size);
        delete[] mem;
        mem = newmem;
        size = minSize;
        memoryMoved = true;
    } else 
        memoryMoved = false;
}

byte* Mem::pointer() { return mem; }

byte* Mem::pointer(int minSize) {
    ensureMinSize(minSize);
    return mem;
}

bool Mem::moved() {
    return memoryMoved;
}

int main() {
    Mem m(10); // Create Mem object with initial size 10

    std::cout << "Memory moved: " << (m.moved() ? "true" : "false") << std::endl;

    byte* ptr = m.pointer(20); // Ensure minimum size of 20
    std::cout << "Memory moved: " << (m.moved() ? "true" : "false") << std::endl;

    delete[] ptr; // Clean up allocated memory

    return 0;
}