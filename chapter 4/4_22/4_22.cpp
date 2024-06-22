#include "Stash.h"
#include "Stack.h"
#include <fstream>
#include <iostream>

int main()
{
    Stack stack;
    stack.initialize();

    std::ifstream is("test");
    std::string line;
    int count = 0;
    Stash *tmp = new Stash;
    tmp->initialize(100);

    while(getline(is, line)) {
        count++;
        const char *lineInc = line.c_str();
        tmp->add(lineInc);

        if (count == 5) {
            stack.push(tmp);
            count = 0;
            tmp = new Stash;
            tmp->initialize(100);
        }
    }

    if (count > 0) {
        stack.push(tmp);
    } else {
        delete tmp; // 如果最后一个 Stash 没有用到，需要手动释放内存
    }

    while(stack.peek() != nullptr) {
        Stash *stash = (Stash *)stack.pop(); 
        for(int i = 0; i < 5; i++) {
            char *line = (char *)stash->fetch(i);
            std::cout << line << std::endl;
        }
        stash->cleanup();
    }

        stack.cleanup();

    return 0;
}