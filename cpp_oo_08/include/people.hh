#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>

class People
{
private:
    const std::string name;
    const std::string lastName;

public:
    typedef const char **FamilyArray;
    const FamilyArray family;

    People(
        const std::string &name,
        const std::string lastName,
        const FamilyArray &family) : name(name), lastName(lastName), family(family) {};
    const FamilyArray getFamily() const;
};

#endif
