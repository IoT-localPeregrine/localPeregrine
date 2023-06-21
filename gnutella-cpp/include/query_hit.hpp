#pragma once

#include <string>
#include <list>

namespace gnutella_cpp
{
    struct File
    {
        uint32_t index;
        uint32_t size;
        std::string name;
    };

    struct QueryHit
    {
        std::list<File> files;
    };
}