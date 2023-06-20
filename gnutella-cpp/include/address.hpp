#pragma once

extern "C"
{
#include <stdint.h>

    struct Address {};

    struct BAddress : Address
    {
        uint16_t address_[6];
    };

    struct TCPAddress : Address
    {
        uint8_t address_[4];
    };
}