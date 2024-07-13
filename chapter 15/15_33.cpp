#include <iostream>
#include <iomanip>
#include <cstring>

class Base {
public:
    Base(int x) : data(x) {}

    virtual void virtualFunc() {
        std::cout << "Base::virtualFunc()" << std::endl;
    }

    int getData() const {
        return data;
    }

private:
    int data;
};

void monitorObjectMemory(Base* obj) {
    std::cout << "Object address: " << std::hex << reinterpret_cast<uintptr_t>(obj) << std::dec << std::endl;

    std::cout << "Object memory layout:" << std::endl;
    size_t objSize = sizeof(*obj);
    const unsigned char* memPtr = reinterpret_cast<const unsigned char*>(obj);

    for (size_t i = 0; i < objSize; ++i) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<unsigned>(memPtr[i]) << " ";
        if ((i + 1) % 16 == 0)
            std::cout << std::endl;
    }
    std::cout << std::dec << std::endl;

    uintptr_t vptrAddr = *reinterpret_cast<uintptr_t*>(obj);
    std::cout << "VPTR address: " << std::hex << vptrAddr << std::dec << std::endl;
}

int main() {
    Base obj(42);

    monitorObjectMemory(&obj);

    return 0;
}