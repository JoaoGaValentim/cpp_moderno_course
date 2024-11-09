#include <iostream>
#include <stdexcept> // Para std::runtime_error

constexpr long int divd(int &x, int &y)
{
    return (x == 0 || y == 0) ? throw std::runtime_error("ZeroDivZeroException") : x / y;
}

int main(int argc, char const *argv[])
{
    int x = 10, y = 10;
    try
    {
        int d = divd(x, y);
        std::cout << d << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
