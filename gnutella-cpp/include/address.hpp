#pragma once

#include <stdint.h>

struct Address
{
    virtual ~Address() = 0;
};

struct BAddress : Address
{
    uint16_t address_[6];
};

struct TCPAddress : Address
{
    uint8_t address_[4];
};