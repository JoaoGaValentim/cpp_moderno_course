#include <iostream>

enum class ColorsRGB : unsigned char
{
    RED = 10,
    GREEN = 20,
    BLUE = 30,
};

auto add_two(int value) -> int
{
    value = value + 2;
    return value;
}

struct Operation
{
    int operator()(int x) const
    {
        return x * 2;
    }
};

auto main(int argc, char **argv) -> int
{
    Operation to;
    int res = to(2);
    std::cout << res << '\n';

    ColorsRGB color = ColorsRGB::GREEN;

    int x = static_cast<int>(color);

    std::cout << x << '\n';

    int value = 2;
    int y = add_two(value);

    std::cout << y << "\n";
    std::cout << value << "\n";

    return 0;
}