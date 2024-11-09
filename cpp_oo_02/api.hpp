#ifndef API_H
#define API_H

#include <iostream>
#include <functional>

class Api
{
public:
    Api();
    ~Api();
    void get(
        std::string path,
        std::function<void(std::string req, std::string res)> callback, // Passar por valor
        std::string req,
        std::string res);
};

#endif