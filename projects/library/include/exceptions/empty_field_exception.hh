#ifndef EMPTY_FIELD_EXCEPTION_H
#define EMPTY_FIELD_EXCEPTION_H

#include <iostream>
#include <exception>

class EmptyFieldException : public std::exception
{
private:
    std::string message;

public:
    EmptyFieldException() : message("EmptyFieldException: TextField is empty") {};

    const char *what() const noexcept override;
};
#endif