#include "../include/models/book_model.hh"
#include "../include/exceptions/empty_field_exception.hh"
#include "../include/models/book_model.hh"
#include "../include/connection_mysql.hh"

BookModel::BookModel(const std::string &name, const std::string &author, unsigned int &id) : name(name), author(author), id(id)
{
    if (name == "" || author == "")
    {
        throw EmptyFieldException();
    }
}

BookModel::~BookModel()
{
}

bool BookModel::save(bool update) const
{
    // Estabelece a conexão com o banco de dados
    ConnectionMySQL conn;

    if (update)
    {
        // Query de atualização: corrigido para incluir as aspas simples
        std::string sql = "UPDATE books SET name = '" + name + "', author = '" + author + "' WHERE ID = " + std::to_string(id);

        // Executa a query
        if (mysql_query(conn.getConnection(), sql.c_str()) == 0)
        {
            return true; // Se a query foi executada com sucesso
        }

        // Se a query falhou, imprime o erro e retorna false
        std::cerr << "Erro ao atualizar livro: " << mysql_error(conn.getConnection()) << std::endl;
        return false;
    }

    // Query de inserção: corrige as aspas simples
    std::string sql = "INSERT INTO books(name, author) VALUES ('" + name + "', '" + author + "')";

    // Executa a query
    if (mysql_query(conn.getConnection(), sql.c_str()) == 0)
    {
        return true; // Se a query foi executada com sucesso
    }

    // Se a query falhou, imprime o erro e retorna false
    std::cerr << "Erro ao inserir livro: " << mysql_error(conn.getConnection()) << '\n';
    return false;
}

bool BookModel::remove() const
{
    ConnectionMySQL conn;
    std::string sql = "DELETE FROM books WHERE id = " + std::to_string(id);

    if (mysql_query(conn.getConnection(), sql.c_str()) == 0)
    {
        return true;
    }
    return false;
}

bool BookModel::update() const
{
    return false;
}

std::vector<BookModel> BookModel::get()
{
    ConnectionMySQL conn;
    std::vector<BookModel> books;
    MYSQL_RES *res;
    MYSQL_ROW row;

    mysql_query(conn.getConnection(), "SELECT * FROM books");

    unsigned int i = 0;

    res = mysql_store_result(conn.getConnection());

    unsigned int num_rows = mysql_num_rows(res);

    while ((row = mysql_fetch_row(res)) != NULL)
    {
        // Convertendo row[1] e row[2] para std::string, e row[0] para int
        std::string name = row[1] ? row[1] : "";
        std::string author = row[2] ? row[2] : "";
        unsigned int id = row[0] ? std::stoi(row[0]) : 0; // Converte o id de const char* para int

        // Criando o objeto BookModel com os valores convertidos
        BookModel b(name, author, id);
        books.push_back(b);
    }

    mysql_free_result(res);

    return books;
}

const std::string BookModel::getName() const
{
    return name;
}

const std::string BookModel::getAuthor() const
{
    return author;
}

unsigned int BookModel::getId() const
{
    return id;
}
