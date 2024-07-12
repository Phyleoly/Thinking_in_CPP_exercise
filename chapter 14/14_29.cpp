//: C13:Framis.cpp
// Local overloaded new & delete
#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>
using namespace std;
ofstream out("Framis.out");

class Framis {
    enum { sz = 10 };
    char c[sz]; // To take up space, not used
    static unsigned char pool[];
    static bool alloc_map[];
public:
    enum { psize = 100 }; // frami allowed
    Framis() { out << "Framis()\n"; }
    virtual ~Framis() { out << "~Framis() ... "; }
    void* operator new(size_t);
    void operator delete(void*);
};

unsigned char Framis::pool[psize * sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};

// Size is ignored -- assume a Framis object
void* Framis::operator new(size_t) {
    for(int i = 0; i < psize; i++)
        if(!alloc_map[i]) {
            out << "using block " << i << " ... ";
            alloc_map[i] = true; // Mark it used
            return pool + (i * sizeof(Framis));
        }
    out << "out of memory" << endl;
    throw bad_alloc();
}

void Framis::operator delete(void* m) {
    if(!m) return; // Check for null pointer
    unsigned long block = (unsigned long)m
        - (unsigned long)pool;
    block /= sizeof(Framis);
    out << "freeing block " << block << endl;
    // Mark it free:
    alloc_map[block] = false;
}

class DerivedFramis : public Framis {
    static unsigned char derived_pool[];
    static bool derived_alloc_map[];
public:
    DerivedFramis() { out << "DerivedFramis()\n"; }
    ~DerivedFramis() { out << "~DerivedFramis() ... "; }
    void* operator new(size_t);
    void operator delete(void*);
};

unsigned char DerivedFramis::derived_pool[psize * sizeof(DerivedFramis)];
bool DerivedFramis::derived_alloc_map[psize] = {false};

// Size is ignored -- assume a DerivedFramis object
void* DerivedFramis::operator new(size_t) {
    for(int i = 0; i < psize; i++)
        if(!derived_alloc_map[i]) {
            out << "using derived block " << i << " ... ";
            derived_alloc_map[i] = true; // Mark it used
            return derived_pool + (i * sizeof(DerivedFramis));
        }
    out << "out of derived memory" << endl;
    throw bad_alloc();
}

void DerivedFramis::operator delete(void* m) {
    if(!m) return; // Check for null pointer
    unsigned long block = (unsigned long)m
        - (unsigned long)derived_pool;
    block /= sizeof(DerivedFramis);
    out << "freeing derived block " << block << endl;
    derived_alloc_map[block] = false;
}

int main() {
    Framis* f[Framis::psize];
    try {
        for(int i = 0; i < Framis::psize; i++)
            f[i] = new Framis;
        new Framis; // Out of memory
    } catch(bad_alloc) {
        cerr << "Out of memory!" << endl;
    }
    delete f[10];
    f[10] = 0;
    Framis* x = new Framis;
    delete x;
    for(int j = 0; j < Framis::psize; j++)
        delete f[j]; // Delete f[10] OK
    
    DerivedFramis* df[DerivedFramis::psize];
    try {
        for(int i = 0; i < DerivedFramis::psize; i++)
            df[i] = new DerivedFramis;
        new DerivedFramis; // Out of memory
    } catch(bad_alloc) {
        cerr << "Out of derived memory!" << endl;
    }
    delete df[10];
    df[10] = 0;
    DerivedFramis* dx = new DerivedFramis;
    delete dx;
    for(int j = 0; j < DerivedFramis::psize; j++)
        delete df[j]; // Delete df[10] OK
} ///:~