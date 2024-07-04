#include <iostream>
#include <cstring> 

#define FIELD(index, a) char* a##_string_##index; int a##_size_##index

class MyClass {
public:
    FIELD(1, field1);
    FIELD(2, field2);
    FIELD(3, field3);

    MyClass() {
        field1_string_1 = new char[1]; 
        field1_size_1 = 1;

        field2_string_2 = new char[2]; 
        strcpy(field2_string_2, "ab");
        field2_size_2 = strlen(field2_string_2);

        field3_string_3 = new char[3]; 
        strcpy(field3_string_3, "xyz");
        field3_size_3 = strlen(field3_string_3);
    }

    char* getFieldString(int index) {
        switch (index) {
            case 1: return field1_string_1;
            case 2: return field2_string_2;
            case 3: return field3_string_3;
            default: return nullptr;
        }
    }

    ~MyClass() {
        delete[] field1_string_1;
        delete[] field2_string_2;
        delete[] field3_string_3;
    }
};

int main() {
    MyClass obj;

    for (int i = 1; i <= 3; ++i) {
        char* str = obj.getFieldString(i);
        if (str) {
            std::cout << "Field " << i << ": " << str << std::endl;
        } else {
            std::cout << "Field " << i << " not found." << std::endl;
        }
    }

    return 0;
}