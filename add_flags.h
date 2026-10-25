#ifndef ADD_FLAGS_H
#define ADD_FLAGS_H

#include <cstdint>
#include "flags.h"

inline void update_add_flags(FlagRegister &flags,
                             uint32_t a, uint32_t b)
{
    uint64_t sum = static_cast<uint64_t>(a) + b;
    uint32_t result = static_cast<uint32_t>(sum);

    flags.ZF = (result == 0);

    flags.SF = ((result >> 31) & 1) != 0;

    flags.CF = (sum > 0xFFFFFFFFULL);

    flags.OF =
        ((~(a ^ b) & (a ^ result) & 0x80000000U) != 0);
}

#endif
