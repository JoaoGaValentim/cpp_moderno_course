#include "../include/exceptions/empty_field_exception.hh"

const char *EmptyFieldException::what() const noexcept
{
    return message.c_str();
}