#pragma once

#include <stdint.h>

namespace gnutella_cpp
{
    struct Peer
    {
        std::string id;
        uint32_t number_of_files_shd;
        uint32_t number_of_kb_shd;
    };
}