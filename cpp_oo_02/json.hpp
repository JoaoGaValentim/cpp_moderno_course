#include <string>
#ifndef JSON_H
#define JSON_H

class JSON
{
private:
    const std::string URL = "https:://lorem.json/api";

public:
    JSON();
    ~JSON();
    std::string formatJSON() const;
    friend class Api;
};

#endif