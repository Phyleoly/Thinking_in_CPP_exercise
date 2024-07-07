#include <iostream>
#include <vector>
using namespace std;

#define DF(N) std::string N() { \
    return "function " #N " called..."; }

DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);

class FuncPtrs {
private:
    std::vector<std::string (*)()> func_table;
public:
    void add(std::string (*ptr)()) {
        func_table.push_back(ptr);
    }

    void remove(std::string (*ptr)()) {
        for(std::vector<std::string (*)()>::iterator it = func_table.begin(); it != func_table.end(); it++) {
            if(*it = ptr) {
                func_table.erase(it);
                break;
            }
        }
    }

    void run() {
        for(std::vector<std::string (*)()>::iterator it =func_table.begin(); it != func_table.end(); it++) {
            std::cout << (*it)() << std::endl;
        }
    }
};

int main()
{
    FuncPtrs obj;
    obj.add(a);
    obj.add(b);
    obj.add(c);
    obj.add(d);
    
    obj.run();

    return 0;
}