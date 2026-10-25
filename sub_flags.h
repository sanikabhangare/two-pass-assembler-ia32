#ifndef SUB_FLAGS_H
#define SUB_FLAGS_H

#include <cstdint>
#include "flags.h"

inline void update_sub_flags(FlagRegister &flags,
                             uint32_t a, uint32_t b)
{
    uint32_t result = a - b;

    
    flags.ZF = (result == 0);

    
    flags.SF = ((result >> 31) & 1) != 0;
  
    flags.CF = (a < b);

    
    flags.OF =
        (((a ^ b) & (a ^ result) & 0x80000000U) != 0);
}

#endif
