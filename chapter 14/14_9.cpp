#include <iostream>
#include <vector>
#include <string>

class StringVector : public std::vector<void*> {
public:
    void push_back(std::string* sptr) {
        std::vector<void*>::push_back((void*)sptr);
    }

    std::string* operator[](size_t index) {
        return (std::string*)std::vector<void*>::operator[](index);
    }
};

int main() {
    StringVector sv;

    std::string s1 = "Hello";
    std::string s2 = "World";

    sv.push_back(&s1);
    sv.push_back(&s2);

    for (size_t i = 0; i < sv.size(); ++i) {
        std::cout << *sv[i] << std::endl;
    }

    void* ptr = nullptr;
    // sv.push_back(ptr); 

    return 0;
}