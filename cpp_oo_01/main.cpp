#include <iostream>
#include "student.hpp"

int main(int argc, char const *argv[])
{
    Student student(
        "12345",
        "Classe A",
        "Imper",
        "Leandro",
        "Daniela");

    student.setName("Joao");
    student.setAge(23);
    student.setCpf("111.111.111-11");
    student.setRg("11.111.111-1");
    student.setAddress("Rua Antonio Candido Batista");
    student.setComplement("Casa");

    student.data();

    return 0;
}
