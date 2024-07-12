#include <iostream>

class Subject {
public:
    virtual void f() = 0;
    virtual void g() = 0;
    virtual void h() = 0;
};

class Implementation1 : public Subject {
public:
    void f() override { std::cout << "Implementation1: f()" << std::endl; }
    void g() override { std::cout << "Implementation1: g()" << std::endl; }
    void h() override { std::cout << "Implementation1: h()" << std::endl; }
};

class Implementation2 : public Subject {
public:
    void f() override { std::cout << "Implementation2: f()" << std::endl; }
    void g() override { std::cout << "Implementation2: g()" << std::endl; }
    void h() override { std::cout << "Implementation2: h()" << std::endl; }
};

class Proxy : public Subject {
private:
    Subject *subject; 

public:
    Proxy(Subject *subj) : subject(subj) {}

    void f() override { subject->f(); }
    void g() override { subject->g(); }
    void h() override { subject->h(); }

    void changeImplementation(Subject *subj) {
        subject = subj;
    }
};

int main() {
    Implementation1 imp1;
    Implementation2 imp2;

    Proxy proxy1(&imp1);
    Proxy proxy2(&imp2);

    std::cout << "Using Proxy 1:" << std::endl;
    proxy1.f();
    proxy1.g();
    proxy1.h();

    std::cout << "\nUsing Proxy 2:" << std::endl;
    proxy2.f();
    proxy2.g();
    proxy2.h();

    std::cout << "\nChanging Proxy 1 to use Implementation2:" << std::endl;
    proxy1.changeImplementation(&imp2);
    proxy1.f();
    proxy1.g();
    proxy1.h();

    return 0;
}