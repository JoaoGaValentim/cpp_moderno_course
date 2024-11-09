#include <iostream>

/// @brief replace
/// @param str
/// @param before
/// @param after
/// @return str
inline auto replace(std::string &str, const std::string &before, const std::string &after) -> std::string
{
    size_t position = str.find(before);

    while (position != std::string::npos)
    {
        str.replace(position, before.length(), after);
        position = str.find(before, after.length() + 1);
    }

    return str;
}

auto main(int argc, char const *argv[]) -> int
{
    std::string date_in("11/10/24");
    std::string date_compare("11/12/24");

    std::cout << (date_compare.compare(date_in) == 0 ? "Y" : "N") << '\n';

    date_in.swap(date_compare);

    std::cout << date_in << '\n';

    std::string text = "Eu estou amando aprender C++";

    std::string after_text = replace(text, " ", "");

    std::cout << after_text << '\n';

    return 0;
}
