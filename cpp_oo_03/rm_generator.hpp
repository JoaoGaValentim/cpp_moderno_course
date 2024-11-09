#ifndef RM_GENERATOR_H
#define RM_GENERATOR_H

namespace generator
{
    class RMGenerator
    {
    public:
        RMGenerator();
        ~RMGenerator();
        int generate() const;
    };
} // namespace generator

#endif