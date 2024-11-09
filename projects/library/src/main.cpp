#include <iostream>
#include <vector>
#include "../include/models/book_model.hh"

int main(int argc, char const *argv[])
{
    unsigned int id = 3;
    BookModel book("Chapeuzinho Amarelo", "Joao", id);

    std::vector<BookModel> books = book.get();

    for (const auto &b : books)
    {
        std::cout << "Nome: " << b.getName() << ", Autor: " << b.getAuthor() << '\n';
    }

    return 0;
}
