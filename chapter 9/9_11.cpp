#include <iostream>

enum class Hue {
    red,
    blue,
    yellow
};

class color {
    Hue hue;  

public:
    color(Hue val) : hue(val) {}

    Hue getHue() const {
        return hue;
    }

    void setHue(Hue val) {
        hue = val;
    }
};

int main() {
    color c1(Hue::red);
    std::cout << "Initial color: " << static_cast<int>(c1.getHue()) << std::endl;

    c1.setHue(Hue::blue);
    std::cout << "Updated color: " << static_cast<int>(c1.getHue()) << std::endl;

    return 0;
}
