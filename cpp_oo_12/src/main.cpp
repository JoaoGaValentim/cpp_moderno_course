#include <iostream>
#include <algorithm>
#include <iterator>

auto main(int argc, char const *argv[]) -> int
{
    const char str[] = "dsfdfdsfdesrftwer)Aadsafdadsf";
    auto it = std::find_if_not(std::begin(str), std::end(str), [](char c)
                               { return (std::tolower(c) >= 'a' && std::tolower(c) <= 'z'); });

    std::cout << it << '\n';

    return 0;
}
