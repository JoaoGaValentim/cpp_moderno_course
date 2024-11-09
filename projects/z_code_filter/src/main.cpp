#include <iostream>
#include "../include/match.hh"

auto main(int argc, char const *argv[]) -> int
{
    Match m("^([0-9]{5})-([0-9]{3})$");

    bool match = m.isValid("18792-008");

    if (match)
    {
        std::cout << "Valido" << '\n';
    }

    if (!match)
    {
        std::cout << "Invalido" << '\n';
    }

    return 0;
}
