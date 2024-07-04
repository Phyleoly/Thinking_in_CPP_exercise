#include <iostream>
#include <cstring>
const int sz = 20;

struct Holder {
private:
    int a[sz];
public:
    void initialize() { memset(a, 0, sz * sizeof(int)); }
    struct Pointer;
    friend Pointer;
    struct Pointer {
    private:
        Holder* h;
        int* p;
    public:
        void initialize(Holder* rv) {
            h = rv;
            p = rv->a;
        }
        void next() { 
            if(p < &(h->a[sz - 1]))
                p++;
        }
        void previous() {
            if(p > &(h->a[0]))
                p--;
        }
        void top() {
            p = &(h->a[0]);
        }
        void end() {
            p = &(h->a[sz - 1]);
        }
        int read() {
            return *p;
        }
        void set(int i) { *p = i; }
    };
};

int main() {
    Holder h;
    Holder::Pointer hp, hp2;
    int i;

    h.initialize();
    hp.initialize(&h);
    hp2.initialize(&h);
    for(int i = 0; i < sz; i++) {
        hp.set(i);
        hp.next();
    }
    hp.top();
    hp2.end();
    for(int i = 0; i < sz; i++) {
        std::cout << "hp = " << hp.read()
             << ", hp2 = " << hp2.read() << std::endl;
        hp.next();
        hp2.previous();
    }

    return 0;
}