#include "Mem.h"
#include <cstring>

Mem::Mem(int sz) {
    mem = 0;
    size = 0;
    if(sz != 0)
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
    }
}

byte* Mem::pointer(int minSize) {
    if(minSize != 0)
        ensureMinSize(minSize);
    return mem;
}