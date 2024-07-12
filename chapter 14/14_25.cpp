#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class StringStack {
private:
    std::vector<std::string> stack;
public:
    void push(std::string* str) {
        stack.push_back(*str);
    }

    std::string* peek() const {
        if(stack.empty())
            return nullptr;
        std::string str = stack.back();
        return &str;
    }

    std::string* pop() {
        if(stack.empty()) {
            return nullptr;
        }
        std::string top = stack.back();
        stack.pop_back();
        return &top;
    }

    friend std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& s) {
        for (const auto& str : s) {
            os << str << " ";
        }
        os << std::endl;
        return os;
    }
};

int main() {
    std::ifstream in("14_25.cpp");
    std::string line;   
    StringStack textlines;
    while(getline(in, line))
        textlines.push(new std::string(line));
    std::string* s;
    while((s = textlines.pop()) != 0)
        std::cout << *s << std::endl;
}