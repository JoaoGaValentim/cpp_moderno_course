#ifndef REGEXP_H
#define REGEXP_H

#include <regex>
#include <iostream>

class Regexp
{
public:
    virtual ~Regexp() {};
    virtual bool isValid(const std::string &s) = 0;
};

#endif