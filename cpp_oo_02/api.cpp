#include "api.hpp"
#include "json.hpp"

Api::Api()
{
}

Api::~Api()
{
}

void Api::get(std::string path, std::function<void(std::string req, std::string res)> callback, std::string req, std::string res)
{
    JSON json;
    std::cout << json.URL << '\n';
    callback(req, res);
}
