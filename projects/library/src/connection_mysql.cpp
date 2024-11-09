#include <iostream>
#include "connection_mysql.hh"
#include "../include/exceptions/connection_exception.hh"

ConnectionMySQL::ConnectionMySQL()
{
    this->connect = mysql_init(NULL);
    this->connect = mysql_real_connect(connect,
                                       "localhost",
                                       "xxxx",
                                       "xxxx",
                                       "library",
                                       0,
                                       NULL,
                                       0);

    // No Success
    if (!this->connect)
    {
        throw ConnectionException();
    }
}

ConnectionMySQL::~ConnectionMySQL()
{
    mysql_close(this->connect);
}

MYSQL *ConnectionMySQL::getConnection()
{
    return this->connect;
}
