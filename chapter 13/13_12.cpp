#include <iostream>
#include <chrono>
#include <new>
#include <cstddef>
#include <fstream>

using namespace std;
ofstream out("Framis.out");

class Framis {
    enum { sz = 10 };
    char c[sz]; 
    static unsigned char pool[];
    static bool alloc_map[];
public:
    enum { psize = 100 }; 
    Framis() { out << "Framis()\n"; }
    ~Framis() { out << "~Framis() ... "; }
    void* operator new(size_t) throw(bad_alloc);
    void operator delete(void*);
};

unsigned char Framis::pool[Framis::psize * sizeof(Framis)];
bool Framis::alloc_map[Framis::psize] = {false};

void* Framis::operator new(size_t) throw(bad_alloc) {
    for (int i = 0; i < psize; i++) {
        if (!alloc_map[i]) {
            out << "using block " << i << " ... ";
            alloc_map[i] = true; 
            return pool + (i * sizeof(Framis));
        }
    }
    out << "out of memory" << endl;
    throw bad_alloc();
}

void Framis::operator delete(void* m) {
    if (!m) return; 
    unsigned long block = (unsigned long)m
      - (unsigned long)pool;
    block /= sizeof(Framis);
    out << "freeing block " << block << endl;
    alloc_map[block] = false;
}

const int N = 100000; 

int main() {
    Framis* f[N];

    auto start_custom = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        f[i] = new Framis;
    }
    for (int i = 0; i < N; ++i) {
        delete f[i];
    }
    auto end_custom = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_custom = end_custom - start_custom;

    auto start_global = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        f[i] = static_cast<Framis*>(::operator new(sizeof(Framis)));
    }
    for (int i = 0; i < N; ++i) {
        ::operator delete(f[i]);
    }
    auto end_global = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_global = end_global - start_global;

    cout << "定制 new/delete 时间: " << elapsed_custom.count() << " 秒\n";
    cout << "全局 new/delete 时间: " << elapsed_global.count() << " 秒\n";

    return 0;
}
