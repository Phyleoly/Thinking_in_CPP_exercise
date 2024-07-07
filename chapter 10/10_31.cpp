#include <iostream>

class SinglePointerConnection {
private:
    int* dataPtr; 

public:
    SinglePointerConnection() : dataPtr(nullptr) {}

    ~SinglePointerConnection() {
        delete dataPtr;
    }

    SinglePointerConnection(const SinglePointerConnection&) = delete;
    SinglePointerConnection& operator=(const SinglePointerConnection&) = delete;

    void setPointer(int* ptr) {
        dataPtr = ptr;
    }

    int* getPointer() const {
        return dataPtr;
    }

    void displayConnectionInfo() const {
        std::cout << "Single Pointer Connection:";
        if (dataPtr) {
            std::cout << " Pointer address: " << dataPtr << ", Value: " << *dataPtr;
        } else {
            std::cout << " No pointer set.";
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglePointerConnection spc;

    int* ptr1 = new int(42);
    spc.setPointer(ptr1);
    spc.displayConnectionInfo();

    int* ptr2 = new int(100);
    spc.setPointer(ptr2);
    spc.displayConnectionInfo();

    delete ptr2;  

    return 0;
}
