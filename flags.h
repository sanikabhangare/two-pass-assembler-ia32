#ifndef FLAGS_H
#define FLAGS_H

#include <iostream>

struct FlagRegister
{
    bool ZF = false;  // Zero Flag
    bool SF = false;  // Sign Flag
    bool CF = false;  // Carry Flag
    bool OF = false;  // Overflow Flag

    void reset()
    {
        ZF = SF = CF = OF = false;
    }

    void display() const
    {
        std::cout << "[ZF=" << ZF
                  << " SF=" << SF
                  << " CF=" << CF
                  << " OF=" << OF << "]";
    }
};

#endif
