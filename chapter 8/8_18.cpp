class X {};

X f() { return X(); }

void g1(X&) {}
void g2(const X&) {}

int main() {
    //  g1(f());
    g2(f());

    return 0;
}