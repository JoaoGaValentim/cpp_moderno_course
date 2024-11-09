#ifndef CONNECTION_MYSQL_H
#define CONNECTION_MYSQL_H

#include <mysql/mysql.h>

class ConnectionMySQL
{
private:
    MYSQL *connect;

public:
    ConnectionMySQL();
    ~ConnectionMySQL();
    MYSQL *getConnection();
};

#endif