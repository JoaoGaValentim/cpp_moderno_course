#include <iostream>
#include "rm_generator.hpp"

int main(int argc, char const *argv[])
{
    generator::RMGenerator gen;

    for (size_t i = 1; i <= 10; i++)
    {
        std::cout << " | " << i << " : " << gen.generate() << " | " << '\n';
    }

    return 0;
}
