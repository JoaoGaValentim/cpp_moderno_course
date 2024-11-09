#include <iostream>
#include <ctime>

std::string format(int num)
{
    std::string fmt = (num < 10) ? "0" + std::to_string(num) : std::to_string(num);
    return fmt;
}

auto main(int argc, char const **argv) -> int
{
    time_t now = time(0);
    char *datetime = ctime(&now);

    std::cout << datetime;

    // parts date
    std::tm *time = localtime(&now);

    std::cout << (time->tm_year + 1900) << '/';
    std::cout << (time->tm_mon + 1) << '/';
    std::cout << time->tm_mday << '\n';

    std::cout << format(time->tm_hour) << ':';
    std::cout << format(time->tm_min) << ':';
    std::cout << format(time->tm_sec) << '\n';

    return 0;
}
