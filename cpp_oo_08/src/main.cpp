#include <iostream>
#include "../include/people.hh"
#include "../include/list.hh"

void showNames(const std::string &value)
{
    std::cout << "Name: " << value << '\n';
}

int main(int argc, char const **argv)
{
    std::string *data = new std::string[3];
    data[0] = "maçã";
    data[1] = "banana";
    data[2] = "cereja";

    List<std::string> names(data, 3);

    names.forEach(showNames);

    return 0;
}
