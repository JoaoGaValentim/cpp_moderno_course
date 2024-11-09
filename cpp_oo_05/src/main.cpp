#include <iostream>

constexpr long int fib(int n)
{
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
    int f = fib(20);
    std::cout << f << '\n';
    return 0;
}
