#include "time.hpp"
#include <ctime>

int Time::getYear() const
{
    std::time_t now = std::time(0);
    std::tm *tm = std::localtime(&now);
    int yearNow = tm->tm_year + 1900;
    return yearNow;
}