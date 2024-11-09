#include <iostream>
#include <fmt/format.h>
#include "student.hpp"
#include "time.hpp"

Student::~Student()
{
}

int Student::getBirthYear() const
{
    Time *datatime;
    const int YEAR = datatime->getYear();
    return YEAR - age;
}

void Student::setName(const std::string &name)
{
    this->name = name;
}

void Student::setAddress(const std::string &address)
{
    this->address = address;
}

void Student::setRg(const std::string &rg)
{
    this->rg = rg;
}

void Student::setCpf(const std::string &cpf)
{
    this->cpf = cpf;
}

void Student::setComplement(const std::string &complement)
{
    this->complement = complement;
}

void Student::setState(const std::string &state)
{
    this->state = state;
}

void Student::setAge(const int &age)
{
    this->age = age;
}

const char *Student::getData(const People &people)
{
    const char *content = "=== Dados === \n"
                          "Nome: {} \n"
                          "Idade: {} \n"
                          "Ano Nasc.: {} \n"
                          "RM: {} \n"
                          "CPF: {} \n"
                          "RG: {} \n"
                          "Estado: {} \n"
                          "Endereco: {} \n"
                          "Complemento: {} \n"
                          "Mae: {} \n"
                          "Pai: {}  \n";
    const char *data = fmt::format(content,
                                   name,
                                   age,
                                   getBirthYear(),
                                   rm,
                                   cpf,
                                   rg,
                                   state,
                                   address,
                                   complement,
                                   mother,
                                   dad)
                           .c_str();
    return data;
}

void Student::data()
{
    std::cout << "Nome => " << name << '\n';
    std::cout << "Idade => " << age << '\n';
    std::cout << "Ano Nasc. => " << getBirthYear() << '\n';
    std::cout << "RM => " << rm << '\n';
    std::cout << "RG => " << rg << '\n';
    std::cout << "CPF => " << cpf << '\n';
    std::cout << "Casa => " << address << '\n';
    std::cout << "Mae => " << mother << '\n';
    std::cout << "Pai => " << dad << '\n';
}
