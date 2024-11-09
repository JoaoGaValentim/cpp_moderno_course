#include <iostream>
#include "api.hpp"

int main(int argc, char const **argv)
{
    Api *api;

    api->get("/", [&api](std::string req, std::string res)
             { std::cout << "Request: " << req << ", Response: " << res << '\n'; }, "GET /", "200 OK");

    return 0;
}
