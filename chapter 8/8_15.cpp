class X {
    int i;
public:
    X(int ii = 0);
    void modify();
};

X::X(int ii) { i = ii; }

void X::modify() { i++; }

X f5() {
    return X();
}

const X f6() {
    return X();
}

void f7(X& x) {
    x.modify();
}

int main() {
    f5() = X(1);
    f5().modify();
    //  f7(f5());
    //  f6() = X(1);
    //  f6().modify();

    return 0;
}