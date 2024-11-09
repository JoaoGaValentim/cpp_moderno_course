#include <iostream>

template <class T>
class Stack
{
public:
    void print(T stack, int max)
    {
        int i{0};

        while (i < max)
        {
            std::cout << stack[i] << " - pos " << i << '\n';
            ++i;
        }
    }
};

int main(int argc, char const *argv[])
{
    Stack<const std::string *> s;
    std::string states[]{"Alegre", "Feliz"};

    std::string *pstates = states;

    int max = sizeof(states) / sizeof(states[0]);

    s.print(states, max);

    return 0;
}
