#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "people.hpp"

/**
 * @class Student
 * @brief Student Object Class
 * @param rm
 * @param sclass
 * @param school
 * @param dad
 * @param mother
 */
class Student : public People
{
private:
    std::string rm;
    std::string sclass;
    std::string school;
    std::string dad;
    std::string mother;

public:
    Student(
        const std::string rm,
        const std::string sclass,
        const std::string school,
        const std::string dad,
        const std::string mother) : rm(rm),
                                    sclass(sclass),
                                    school(school),
                                    dad(dad),
                                    mother(mother) {};
    ~Student();
    int getBirthYear() const override;
    void setName(const std::string &name) override;
    void setAddress(const std::string &address) override;
    void setRg(const std::string &rg) override;
    void setCpf(const std::string &cpf) override;
    void setComplement(const std::string &complement) override;
    void setState(const std::string &state) override;
    void setAge(const int &age) override;
    const char *getData(const People &people) override;
    void data() override;
};

#endif