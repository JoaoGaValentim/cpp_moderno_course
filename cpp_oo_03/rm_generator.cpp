#include "rm_generator.hpp"
#include <random>
#include <unordered_set>

generator::RMGenerator::RMGenerator()
{
}

generator::RMGenerator::~RMGenerator()
{
}

int generator::RMGenerator::generate() const
{
    std::random_device rd;                             // Obtain a random seed from the hardware
    std::mt19937 gen(rd());                            // Mersenne Twister engine with the random seed
    std::uniform_int_distribution<> dis(10000, 19999); // Distribution range [1, 100]
    int randRm = dis(gen);                             // RM rand
    return randRm;
}
