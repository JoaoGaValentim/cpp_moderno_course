#include <iostream>
#include "../include/people.hh"

int main(int argc, char const **argv)
{
    const char *brothers[] = {"Guilherme", "Heloisa"};
    People p("Joao", "Theodoro", brothers);

    constexpr int size = sizeof(brothers) / sizeof(brothers[0]);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << p.getBrothers()[i] << " ";
    }

    std::cout << '\n';

    return 0;
}
