#include <iostream>
#include <new> 
#include <vector>

using namespace std;

class NoMemory {
public:
    NoMemory() {
        cout << "NoMemory::NoMemory" << endl;
    }

    void* operator new(size_t sz) throw(bad_alloc) {
        cout << "NoMemory::operator new" << endl;
        void* ptr = ::operator new(sz);
        if (!ptr) {
            throw bad_alloc(); 
        }
        return ptr;
    }

    int data[100]; 
};

int main() {
    vector<NoMemory*> objects;
    try {
        while (true) {
            NoMemory* nm = new NoMemory;
            objects.push_back(nm);
        }
    } catch (bad_alloc&) {
        cerr << "Out of memory exception" << endl;
    }

    cout << "Allocated " << objects.size() << " objects" << endl;

    for (size_t i = 0; i < objects.size(); ++i) {
        delete objects[i];
    }

    return 0;
}
