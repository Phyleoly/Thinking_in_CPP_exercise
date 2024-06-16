#include <iostream>

void setBytes(void *ptr, size_t num, unsigned char value) {
    unsigned char *bytePtr = static_cast<unsigned char *>(ptr);
    for(int i = 0; i < num; i++) {
        bytePtr[i] = value;
    }
}

int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    void *voidPtr = static_cast<void *>(arr);

    setBytes(voidPtr, 5, 10);

    for(int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";

    return 0;
}