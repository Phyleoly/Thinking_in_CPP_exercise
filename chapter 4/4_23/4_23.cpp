#include "Stash.h"
#include "Stack.h"
#include <fstream>
#include <iostream>

struct StashStack {
    Stack stack;
    Stash* currentStash;

    StashStack() {
        stack.initialize();
        currentStash = new Stash;
        currentStash->initialize(100);
    }

    ~StashStack() {
        stack.cleanup();
        delete currentStash;
    }

    void addLine(const std::string& line) {
        const char* lineInc = line.c_str();
        currentStash->add(lineInc);
        if (currentStash->count() == 5) {
            stack.push(currentStash);
            currentStash = new Stash;
            currentStash->initialize(100);
        }
    }

    void printAll() {
        while (stack.peek() != nullptr) {
            Stash* stash = static_cast<Stash*>(stack.pop());
            for (int i = 0; i < 5; ++i) {
                char* line = static_cast<char*>(stash->fetch(i));
                if (line != nullptr) {
                    std::cout << line << std::endl;
                }
            }
            stash->cleanup();
            delete stash;
        }
    }
};

int main() {
    StashStack stashStack;

    std::ifstream is("test");
    std::string line;
    
    while (getline(is, line)) {
        stashStack.addLine(line);
    }

    stashStack.printAll();

    return 0;
}