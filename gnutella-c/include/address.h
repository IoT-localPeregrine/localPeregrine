#pragma once

#include "utils.h"
#include "type.h"

struct Address
{
    union {
        uint8_t data_TCP[4];
        uint16_t data_BT[6];
    };
    INetType type;
};
