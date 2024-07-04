#include <iostream>
typedef enum {
    red,
    blue,
    yellow
} Hue;

class color {
    Hue hue;
public:
    color(Hue val) : hue(val) {}
    Hue getHue() { return hue; }
    void setHue(Hue val) { hue = val; }
};

int main() {
    // 测试 color 类的用法
    color c1(Hue::red);
    std::cout << "Initial color: " << static_cast<int>(c1.getHue()) << std::endl;

    c1.setHue(Hue::blue);
    std::cout << "Updated color: " << static_cast<int>(c1.getHue()) << std::endl;

    return 0;
}