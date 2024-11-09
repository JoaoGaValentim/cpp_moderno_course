#include "../include/exceptions/connection_exception.hh"

const char *ConnectionException::what() const noexcept
{
    return message.c_str();
}