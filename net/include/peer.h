#pragma once

#include "address.h"
#include "utils.h"

struct Peer {
    Address address;
    uint32_t number_of_files_shd;
    uint32_t number_of_kb_shd;
};
