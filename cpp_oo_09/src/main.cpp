#include <iostream>
#include <sqlite3.h>

int main(int argc, char const *argv[])
{
    sqlite3 *db;
    char *errMsg = 0;

    int resource = sqlite3_open("library.db", &db);

    if (resource)
    {
        std::cerr << "Não conseguiu abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return (0);
    }

    if (!resource)
    {
        std::cout << "Banco de dados aberto com sucesso!" << std::endl;
    }

    const char *createTableSQL = "CREATE TABLE IF NOT EXISTS Books (ID INTEGER PRIMARY KEY, Name TEXT, Author TEXT);";

    resource = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);
    if (resource != SQLITE_OK)
    {
        std::cerr << "Erro ao criar a tabela: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    if (resource == SQLITE_OK)
    {
        std::cout << "Tabela criada com sucesso!" << std::endl;
    }

    // Fechar banco de dados
    sqlite3_close(db);

    return 0;
}
