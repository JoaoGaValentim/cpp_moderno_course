#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>

class People
{
private:
    const std::string name;
    const std::string lastName;

public:
    typedef const char **BrothersArray; // Use const char** instead of char**

    const BrothersArray brothers;

    People(
        const std::string &name,
        const std::string &lastName,
        const BrothersArray &brothers) // Change the parameter type here too
        : name(name), lastName(lastName), brothers(brothers)
    {
    }

    const BrothersArray getBrothers() const
    {
        return this->brothers;
    }
};

#endif
