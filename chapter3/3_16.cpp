#include <iostream>

enum Color {
    red,
    yellow,
    blue,
    green
};

int main()
{
    Color color;
    for(int i = Color::red; i <= Color::green; ++i)
        std::cout << static_cast<int>(i) << " ";

    return 0;
}