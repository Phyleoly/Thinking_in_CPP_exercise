#include <iostream>
#include <cstring>

#define FIELD(index, a) \
private: \
    char* a##_string_##index; \
    int a##_size_##index; \
public: \
    char* get_##a##_string_##index() {return a##_string_##index;} \
    int get_##a##_size_##index() {return a##_size_##index;}

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

    ~MyClass() {
        delete[] field1_string_1;
        delete[] field2_string_2;
        delete[] field3_string_3;
    }
};

int main() {
    MyClass obj;

    std::cout << "Field 1: " << obj.get_field1_string_1() << " (Size: " << obj.get_field1_size_1() << ")" << std::endl;
    std::cout << "Field 2: " << obj.get_field2_string_2() << " (Size: " << obj.get_field2_size_2() << ")" << std::endl;
    std::cout << "Field 3: " << obj.get_field3_string_3() << " (Size: " << obj.get_field3_size_3() << ")" << std::endl;

    return 0;
}