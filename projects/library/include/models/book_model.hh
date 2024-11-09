#ifndef BOOK_MODEL_H
#define BOOK_MODEL_H

#include <iostream>
#include <vector>

class BookModel
{
private:
    const std::string name;
    const std::string author;
    unsigned int id;

public:
    BookModel(const std::string &name,
              const std::string &author,
              unsigned int &id);
    ~BookModel();
    const std::string getName() const;
    const std::string getAuthor() const;
    unsigned int getId() const;
    bool save(bool update = false) const;
    bool remove() const;
    bool update() const;
    std::vector<BookModel> get();
};

#endif