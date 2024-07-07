#include <iostream>

namespace Int {
    enum sign { positive, negative };
    class Integer {
        int i;
        sign s;
    public:
        Integer(int ii = 0) : i(ii), s(i >= 0 ? positive : negative) {}
        sign getSign() const { return s; }
        void setSign(sign sgn) { s = sgn; }
    };
};

namespace Math {
    using namespace Int;
    Integer a, b;
    void divide(Integer, Integer) {
        std::cout << "in Math::divide() " << std::endl;
    }
}

namespace Calculation {
    using namespace Int;
    void divide(Integer, Integer) {
        std::cout << "in Math::divide() " << std::endl;
    }
}

void s() {
    using namespace Math;
    using namespace Calculation;
    Math::divide(1, 2);
    using Calculation::divide;
    divide(1, 2);
}

int main() {
    void s();
    
    return 0;
}