#ifndef MATCH_H
#define MATCH_H

#include "regexp.hh"

class Match : public Regexp
{
private:
    const std::string r;

public:
    Match(const std::string &r) : r(r) {};
    ~Match();
    bool isValid(const std::string &s) override;
};

#endif