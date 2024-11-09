#include <iostream>
#include <random>

auto main(int argc, char const **argv) -> int
{
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<> dis(0, 10);

    std::cout << dis(gen) << '\n';

    return 0;
}
