#ifndef _MEM_H
#define _MEM_H

typedef unsigned char byte;

class Mem {
    byte* mem;
    int size;
public:
    void ensureMinSize(int minSize);
    Mem();
    Mem(int sz);
    ~Mem();
    int msize();
    byte* pointer();
    byte* pointer(int minSize);
};

#endif