#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>

/**
 * @class People
 * @brief Meta Class
 * @param name
 * @param rg
 * @param cpf
 * @param address
 * @param complement
 * @param state
 * @param age
 */
class People
{
protected:
    std::string name;
    std::string rg;
    std::string cpf;
    std::string address;
    std::string complement;
    std::string state;
    int age;

public:
    // virtual nao pode ser estatica
    virtual ~People() {};
    virtual int getBirthYear() const = 0;
    virtual const char *getData(const People &people) = 0;
    virtual void setName(const std::string &name) = 0;
    virtual void setRg(const std::string &rg) = 0;
    virtual void setCpf(const std::string &cpf) = 0;
    virtual void setAddress(const std::string &address) = 0;
    virtual void setComplement(const std::string &complement) = 0;
    virtual void setState(const std::string &state) = 0;
    virtual void setAge(const int &age) = 0;
    /// this fuction show a object child property.
    virtual void data() = 0;
};

#endif