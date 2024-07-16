#include <set>    
#include <iostream>
#include <string>

class AutoCounter {
    static int count;
    int id;
    std::string className;
    class CleanupCheck {
        std::set<AutoCounter*> trace;
    public:
        void add(AutoCounter* ap) {
            trace.insert(ap);
        }
        void remove(AutoCounter* ap) {
            trace.erase(ap);
        }
        ~CleanupCheck() {
            std::cout << "~CleanupCheck()" << std::endl;
        }
    };
    static CleanupCheck verifier;
    AutoCounter(const std::string& name) : id(count++), className(name) {
        verifier.add(this); 
        std::cout << "created[" << id << "] of " << className << std::endl;
    }
    AutoCounter(const AutoCounter&);
    void operator=(const AutoCounter&);
public:
    static AutoCounter* create(const std::string& name) {
        return new AutoCounter(name);
    }
    ~AutoCounter() {
        std::cout << "destroying[" << id << "] of " << className << std::endl;
        verifier.remove(this);
    }

    friend std::ostream& operator<<(std::ostream& os, const AutoCounter& ac) {
        return os << "AutoCounter[" << ac.id << "] of " << ac.className;
    }

    friend std::ostream& operator<<(std::ostream& os, const AutoCounter* ac) {
        return os << "AutoCounter[" << ac->id << "] of " << ac->className;
    }
};

int AutoCounter::count = 0;
AutoCounter::CleanupCheck AutoCounter::verifier;

class MyClass {
    AutoCounter* ac;
public:
    MyClass(const std::string& name) {
        ac = AutoCounter::create(name);
    }
    ~MyClass() {
        delete ac;
    }
};

int main() {
    MyClass obj1("MyClass");
    MyClass obj2("MyClass");

    return 0;
}