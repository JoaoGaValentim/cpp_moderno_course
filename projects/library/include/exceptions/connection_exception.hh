#ifndef CONNECTION_EXCEPTION_H
#define CONNECTION_EXCEPTION_H

#include <iostream>
#include <exception>

class ConnectionException : public std::exception
{
private:
    std::string message;

public:
    ConnectionException() : message("ConnectioException: Database connection exception") {};

    const char *what() const noexcept override;
};

#endif