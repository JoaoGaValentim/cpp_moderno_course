#include "../include/match.hh"
#include <regex>

Match::~Match() {}

bool Match::isValid(const std::string &s)
{
    std::regex regexp(r);
    std::smatch match;

    bool isValid = std::regex_match(s, match, regexp);

    return isValid;
}
